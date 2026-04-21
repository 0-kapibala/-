import gymnasium as gym
import torch
from rl.prac1.agents import DQNAgent
from rl.prac1 import modules


class TrainManager:
    def __init__(self, env, lr=0.01, episodes=500, gamma=0.99, e_greed=0.1):
        self.env = env
        self.lr = lr
        self.gamma = gamma
        self.epsilon = e_greed
        self.episodes = episodes

        n_obs = env.observation_space.shape[0]
        n_actions = env.action_space.n

        self.q_func = modules.MLP(n_obs, n_actions)
        self.agent = DQNAgent(
            self.q_func,
            n_actions,
            lr=self.lr,
            gamma=self.gamma,
            e_greed=self.epsilon
        )

    def train_episode(self):
        total_reward = 0
        obs, info = self.env.reset()
        obs = torch.FloatTensor(obs)

        while True:
            action = self.agent.act(obs)
            next_obs, reward, terminated, truncated, info = self.env.step(action)
            done = terminated or truncated

            next_obs = torch.FloatTensor(next_obs)
            self.agent.learn(obs, action, reward, next_obs, done)

            obs = next_obs
            total_reward += reward

            if done:
                break

        return total_reward

    def test_episode(self):
        total_reward = 0
        obs, info = self.env.reset()
        obs = torch.FloatTensor(obs)

        while True:
            action = self.agent.predict(obs)
            next_obs, reward, terminated, truncated, info = self.env.step(action)
            done = terminated or truncated

            next_obs = torch.FloatTensor(next_obs)
            total_reward += reward
            obs = next_obs

            if done:
                break

        return total_reward

    def train(self):
        for episode in range(self.episodes):
            ep_reward = self.train_episode()
            print(f"Episode {episode + 1}, Train Reward: {ep_reward}")

            if (episode + 1) % 10 == 0:
                test_reward = self.test_episode()
                print(f"Episode {episode + 1}, Test Reward: {test_reward}")


if __name__ == '__main__':
    env = gym.make('CartPole-v1', render_mode='human')
    tm = TrainManager(env)
    tm.train()