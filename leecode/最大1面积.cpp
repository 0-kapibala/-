#include <bits/stdc++.h>
using namespace std;
int maximalSquare(vector<vector<char>>& matrix){
	if (matrix.empty()||matrix[0].empty()) return 0;
	int n=static_cast<int>(matrix.size()),m=static_cast<int>(matrix[0].size()),max_side=0;
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	
	for (int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(matrix[i-1][j-1]=='1')
			dp[i][j]=min(dp[i][j],min(dp[i-1][j],dp[i][j-1]))+1;
			max_side=max(max_side,dp[n][m]);
		}
	}
	
	return max_side*max_side;
}

int main()
{
return 0;
}
