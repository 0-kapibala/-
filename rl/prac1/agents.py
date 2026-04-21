import random
import numpy as np
import torch

class DQNAgent(object):
    def __init__(self, q_func, n_act, lr=0.01, gamma=0.9, e_greed=0.1):
        self.q_func = q_func
        self.criterion = torch.nn.MSELoss()
        self.optimizer = torch.optim.Adam(self.q_func.parameters(), lr=lr)
        self.n_act = n_act
        self.lr = lr
        self.gamma = gamma
        self.epsilon = e_greed

    def predict(self, obs):
        Q_list = self.q_func(obs)
        action = int(torch.argmax(Q_list).detach().numpy())
        return action

    def act(self, obs):
        if np.random.uniform() < self.epsilon:
            action = np.random.choice(self.n_act)
        else:
            action = self.predict(obs)
        return action

    def learn(self, obs, action, reward, next_obs, done):
        predict_Q = self.q_func(obs)[action]
        target_Q = reward + self.gamma * (1 - done) * self.q_func(next_obs).max()
        self.optimizer.zero_grad()
        loss = self.criterion(predict_Q, target_Q)
        loss.backward()
        self.optimizer.step()

