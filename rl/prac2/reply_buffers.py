import random
import collections
import torch

class ReplayBuffer():
    def __init__(self, max_size,num_steps=4):
        self.buffer = collections.deque(maxlen=max_size)
        self.num_steps = num_steps
    def append(self,buffer_size):
        self.buffer.append(buffer_size)

    # reply_buffers.py
    def sample(self, batch_size):
        mini_batch = random.sample(self.buffer, batch_size)
        obs_batch, action_batch, reward_batch, next_obs_batch, done_batch = zip(*mini_batch)

        obs_batch = torch.stack(obs_batch)
        action_batch = torch.LongTensor(action_batch)
        reward_batch = torch.FloatTensor(reward_batch)
        next_obs_batch = torch.stack(next_obs_batch)
        done_batch = torch.FloatTensor(done_batch)

        return obs_batch, action_batch, reward_batch, next_obs_batch, done_batch

        return obs_batch,action_batch,reward_batch,next_obs_batch,done_batch
    def __len__(self):
        return len(self.buffer)

