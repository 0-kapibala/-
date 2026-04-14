#include <bits/stdc++.h>
using namespace std;
bool canPartition(vector<int> &nums){
	int sum=accumulate(nums.begin(),nums.end(),0);
	if(sum%2) return false;
	int target=sum/2,n=nums.size();
	vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
	for (int i=0;i<=n;++i){
		dp[i][0]=true;
	}
	for(int i=1;i<=n;++i){
		for(int j=nums[i-1];j<=target;++j){
			dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
		}
	}
	return dp[n][target];
}
bool canPartition2(vector<int> &nums){
	int sum=accumulate(nums.begin(),nums.end(),0);
	if(sum%2) return false;
	int target=sum/2,n=nums.size();
	vector<bool> dp(target+1,false);
	dp[0]=true;
	for(int i=1;i<=n;++i){
		for(int j=target;j>=nums[i-1];--j){
			dp[j]=dp[j-nums[i-1]]||dp[j];
		}
	}
	return dp[target];
}
int main()
{
return 0;
}
