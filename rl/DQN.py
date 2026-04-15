import torch
import torch.nn as nn
import gym
import numpy as np
import random
import torch.optim as optim
import collections

env=gym.make('CartPole-v1')
state_dim=env.observation_space.shape[0]# 状态维度：4 (小车位置，速度，杆角度，角速度)
action_dim=env.action_space.n# 动作维度：2 (向左，向右)

class DQN(nn.Module):
    def __init__(self):
        self.l1=nn.linear(state_dim,128)
        self.l2=nn.Linear(128,128)
        self.l3=nn.Linear(128,action_dim)

    def forward(self,x):
        x=torch.relu(self.l1(x))
        x=torch.relu(self.l2(x))
        return self.l3(x)

class ReplayBuffer:
    def __init__(self,capacity):
        self.buffer = collections.deque(maxlen=capacity)

    def add(self,state,action,reward,next_state,done):
        self.buffer.append((state,action,reward,next_state,done))

    def sample(self,batch_size):
        transitions=random.sample(self.buffer,batch_size)
        state,action,reward,next_state,done=zip(*transitions)
        return (np.array(state),action,reward,np.array(next_state),np.array(done))

    def size(self):
        return len(self.buffer)

class DQNAgent:
    def __init__(self, state_dim, action_dim, lr=1e-3, gamma=0.98, epsilon=0.01,
                 target_update_freq=10, buffer_size=10000, batch_size=64):
        self.action_dim = action_dim
        self.q_net = DQN(state_dim, action_dim)          # 在线网络
        self.target_q_net = DQN(state_dim, action_dim)   # 目标网络
        self.target_q_net.load_state_dict(self.q_net.state_dict()) # 初始参数一致
        self.optimizer = optim.Adam(self.q_net.parameters(), lr=lr) # 优化器

        self.gamma = gamma               # 折扣因子
        self.epsilon = epsilon           # 探索率（最终）
        self.target_update_freq = target_update_freq # 目标网络更新频率
        self.batch_size = batch_size
        self.buffer = ReplayBuffer(buffer_size)
        self.count = 0                   # 记录更新步数

    def take_action(self, state, epsilon=None):
        """根据epsilon-greedy策略选择动作"""
        if epsilon is None:
            epsilon = self.epsilon
        if np.random.random() < epsilon:
            return np.random.randint(self.action_dim)  # 探索：随机选择
        else:
            state = torch.tensor(state, dtype=torch.float).unsqueeze(0) # 增加批次维度
            with torch.no_grad():
                q_values = self.q_net(state)
            return q_values.argmax().item()            # 利用：选择Q值最大的动作

    def update(self):
        """从经验回放池采样并更新网络"""
        if self.buffer.size() < self.batch_size:
            return

        # 1. 采样
        states, actions, rewards, next_states, dones = self.buffer.sample(self.batch_size)
        # 转换为PyTorch张量
        states = torch.tensor(states, dtype=torch.float)
        actions = torch.tensor(actions).unsqueeze(1)      # 形状变为[batch_size, 1]，便于gather操作
        rewards = torch.tensor(rewards, dtype=torch.float).unsqueeze(1)
        next_states = torch.tensor(next_states, dtype=torch.float)
        dones = torch.tensor(dones, dtype=torch.float).unsqueeze(1)

        # 2. 计算当前Q值 (Q(s, a))
        current_q_values = self.q_net(states).gather(1, actions)  # 只取出执行动作a对应的Q值

        # 3. 计算目标Q值 (r + γ * max_a' Q_target(s', a'))
        with torch.no_grad():
            next_q_values = self.target_q_net(next_states).max(1)[0].unsqueeze(1) # 取下一状态的最大Q值
            target_q_values = rewards + self.gamma * next_q_values * (1 - dones) # 如果回合结束(done=1)，则没有未来奖励

        # 4. 计算损失 (均方误差)
        loss = nn.MSELoss()(current_q_values, target_q_values)

        # 5. 梯度下降更新在线网络
        self.optimizer.zero_grad()
        loss.backward()
        # 可选：梯度裁剪，防止梯度爆炸
        # torch.nn.utils.clip_grad_norm_(self.q_net.parameters(), max_norm=10)
        self.optimizer.step()

        self.count += 1
        # 6. 定期更新目标网络
        if self.count % self.target_update_freq == 0:
            self.target_q_net.load_state_dict(self.q_net.state_dict())