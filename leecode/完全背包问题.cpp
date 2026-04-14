#include <bits/stdc++.h>
using namespace std;
int knapsack1(vector<int> weights, vector<int> values, int N, int W){
	vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
	for(int i=1;i<=N;++i){
		int w=weights[i-1],v=values[i-1];
		for(int j=1;j<=W;++j){
			if(j>=w){
				dp[i][j]=max(dp[i-1][j],dp[i][j-w]+v);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[N][W];
}//完全背包问题与0-1背包问题差别仅在于状态转移方程中的第二个 i-1 变成了 i
int knapsack2(vector<int> weights, vector<int> values, int N, int W){
	vector<int> dp(W+1,0);
	for(int i=1;i<=N;++i){
		int v=values[i-1],w=weights[i-1];
		for(int j=w;j<=W;++j){
			dp[j]=max(dp[j],dp[j-w]+v);
		}
	}
	return dp[W];
}//优化从逆向遍历变为正向
int main()
{
return 0;
}
