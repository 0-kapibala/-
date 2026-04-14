#include <bits/stdc++.h>
using namespace std;
//给定一个数组，要求实现两个指令函数。第一个函数“shuffle”可以随机打乱这个数组，
//第二个函数“reset”可以恢复原来的顺序
//Fisher-Yates 洗牌算法，原理是通过随机交换位置来实现随机打乱，有正向和反向两种写法
class Solution{
	vector <int> origin;
	public:
	Solution(vector<int> nums):origin(std::move(nums)){};
	vector<int> reset(){
		return origin;	
	}
	vector<int> shuffle(){
		if(origin.size()==0) return {};	
		vector<int> shuffled(origin);
		int n=origin.size();
		for(int i=n-1;i>=0;--i){
			swap(shuffled[i],shuffled[rand()%(i+1)]);
		}//反向洗牌
		// 正向洗牌：
		// for (int i = 0; i < n; ++i) {
		// int pos = rand() % (n - i);
		// swap(shuffled[i], shuffled[i+pos]);
		// }
		return shuffled;
	}
};
int main()
{
return 0;
}
