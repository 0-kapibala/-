import  numpy as np
import random
Size=6
Episodes=1000
Learning_rate=0.05
Gamma=0.8
Epsilon=0.1
#测试智能体环境
class GridWorld:
    def __init__(self,size=Size):
        self.size=size
        self.state=(0,0)
        self.action=["up","down","left","right"]
        self.goal=(size-1,size-1)
        self.action_map = {
            "up":(-1,0),
            "down":(1,0),
            "left":(0,-1),
            "right":(0,1)
        }

    def reset(self):
        self.state=(0,0)
        return self.state

    def step(self,action):
        move=self.action_map[action]
        nxt_state=(self.state[0]+move[0],self.state[1]+move[1])
        if(nxt_state[0]<0 or nxt_state[0]>self.size-1 or nxt_state[1]<0 or nxt_state[1]>self.size-1):
            nxt_state=self.state

        if nxt_state==self.goal:
            reward=10
            done=True
        else:
            reward=0
            done=False

        return nxt_state,reward,done

    def get_action(self):
        return self.action

#Q-learning实现
def q_learning(env,episodes=Episodes,learning_rate=Learning_rate,gamma=Gamma,epsilon=Epsilon):
    """
       env: 环境对象
       episodes: 训练轮数
       learning_rate: 学习率
       gamma: 折扣因子
       epsilon: ε-greedy 策略中的探索概率
    """
    q_table=np.zeros((env.size,env.size,len(env.action)))
    for episode in range(episodes):
        state = env.reset()
        done=False

        while not done:
            if random.uniform(0,1)<epsilon:
                action_idx=random.randint(0,len(env.action)-1)
            else:
                action_idx=np.argmax(q_table[state[0],state[1],:])
            action=env.action[action_idx]

            next_state,reward,done=env.step(action)

            q_current=q_table[state[0],state[1],action_idx]
            q_next_max=np.max(q_table[next_state[0],next_state[1],:])
            q_target=reward+gamma*q_next_max
            q_table[state[0],state[1],action_idx]=q_current+learning_rate*(q_target-q_current)
            state=next_state

    return q_table

def Sarsa(env,episodes=Episodes,learning_rate=Learning_rate,gamma=Gamma,epsilon=Epsilon):
    q_table = np.zeros((env.size, env.size, len(env.actions)))
    for episode in range(episodes):
        state = env.reset()
        done = False

        if random.uniform(0, 1) < epsilon:
            action_idx = random.randint(0, len(env.action) - 1)
        else:
            action_idx = np.argmax(q_table[state[0], state[1], :])
        action = env.action[action_idx]

        while not done:
            next_state, reward, done = env.step(action)

            if random.uniform(0, 1) < epsilon:
                next_action_idx = random.randint(0, len(env.action) - 1)
            else:
                next_action_idx = np.argmax(q_table[next_state[0], next_state[1], :])
            next_action = env.action[next_action_idx]

            q_current = q_table[state[0], state[1], action_idx]
            q_next = q_table[next_state[0], next_state[1], next_action_idx]
            q_target = reward + gamma *q_next
            q_table[state[0], state[1], action_idx] = q_current + learning_rate * (q_target - q_current)
            state = next_state
            action_idx = next_action_idx
            action = next_action

    return q_table


#Q-learing和Sarsa同出TD算法，但是Q-learning基于下一步最优动作，即off-policy，Sarsa是基于下一步真实动作，即on-policy
#这也是为什么两个函数前面基本一样，只在后面更新时出现不同
#Q-learning偏贪心，Sarsa偏探索
#数学原理见苏神博客和西湖大学RL

def test_policy(env, q_table, episodes=Episodes):
    """测试学到的策略"""
    total_rewards = []
    for _ in range(episodes):
        state = env.reset()
        done = False
        total_reward = 0
        steps = []

        while not done:
            # 测试时使用贪婪策略（不探索）
            action_idx = np.argmax(q_table[state[0], state[1], :])
            action = env.action[action_idx]
            next_state, reward, done = env.step(action)
            steps.append(action[0].upper()) # 记录动作首字母
            total_reward += reward
            state = next_state

        total_rewards.append(total_reward)
        print(f"Episode steps: {steps}, Total reward: {total_reward}")

    print(f"平均奖励: {np.mean(total_rewards):.2f}")

# 创建环境
env = GridWorld(size=Size)

print("=== 训练并测试 Q-learning ===")
q_table_ql = q_learning(env)
test_policy(env, q_table_ql)

print("\n=== 训练并测试 SARSA ===")
env.reset() # 重置环境状态
q_table_sarsa = Sarsa(env)
test_policy(env, q_table_sarsa)

# 简单比较最终策略
print("\n=== 策略对比（从起点(0,0)出发的动作）===")
start_q_values = q_table_ql[0, 0, :]
start_sarsa_values = q_table_sarsa[0, 0, :]
print(f"Q-learning Q值: {dict(zip(env.action, start_q_values))}")
print(f"推荐动作: {env.action[np.argmax(start_q_values)]}")
print(f"SARSA Q值: {dict(zip(env.action, start_sarsa_values))}")
print(f"推荐动作: {env.action[np.argmax(start_sarsa_values)]}")

