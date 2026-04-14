#include <bits/stdc++.h>
using namespace std;
int minPathSum(vector<vector<int>>& grid){
	int m=static_cast<int>(grid.size()),n=static_cast<int>(grid[0].size());
	vector<vector<int>> dp(m,vector<int> (n,0));
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			dp[i][j]=grid[i][j];
		}
	}
	for(int i=1;i<m;++i){
		for(int j=1;j<n;++j){
			dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
		}
	}
	return dp[m-1][n-1];
}

int main()
{
return 0;
}
