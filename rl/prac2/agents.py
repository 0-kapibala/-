import random
import numpy as np
import torch
import torch.nn.functional as F

class DQNAgent(object):
    def __init__(self, q_func,optimizer,reply_buffer,batch_size,reply_start_size,n_act, gamma=0.9, e_greed=0.1):
        self.q_func = q_func
        self.criterion = torch.nn.MSELoss()
        self.optimizer = optimizer
        self.rb=reply_buffer
        self.batch_size = batch_size
        self.reply_start_size = reply_start_size
        self.n_act = n_act
        self.gamma = gamma
        self.epsilon = e_greed
        self.global_step=0
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


    def learn_batch(self, batch_obs, batch_action, batch_reward, batch_next_obs, batch_done):
        q_values = self.q_func(batch_obs)  # [B, n_act]
        predict_Q = q_values.gather(1, batch_action.unsqueeze(1)).squeeze(1)

        with torch.no_grad():
            target_Q = batch_reward + self.gamma * (1 - batch_done) * self.q_func(batch_next_obs).max(1)[0]

        self.optimizer.zero_grad()
        loss = self.criterion(predict_Q, target_Q)
        loss.backward()
        self.optimizer.step()


    def learn(self,obs, action, reward, next_obs, done):
        self.global_step+=1
        self.rb.append((obs, action, reward, next_obs, done))
        if len(self.rb)>self.reply_start_size and (self.global_step % self.rb.num_steps == 0):
            self.learn_batch(*self.rb.sample(self.batch_size))