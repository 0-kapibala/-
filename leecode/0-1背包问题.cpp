#include <bits/stdc++.h>
using namespace std;
int knapsack1(vector<int> weights, vector<int> values, int N, int W){
	vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
	for(int i=1;i<=N;++i){
		int w=weights[i-1],v=values[i-1];
		for(int j=1;j<=W;++j){
			if(j>=w){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w]+v);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[N][W];
}//总时间复杂度和空间复杂度均为NW

int knapsack2(vector<int> weights, vector<int> values, int N, int W){
	vector<int> dp(W+1,0);
	for(int i=1;i<=N;++i){
		int v=values[i-1],w=weights[i-1];
		for(int j=W;j>=w;--j){
			dp[j]=max(dp[j],dp[j-w]+v);
		}
	}
	return dp[W];
}//空间复杂度优化为W

int main()
{
return 0;
}
