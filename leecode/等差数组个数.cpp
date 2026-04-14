#include <bits/stdc++.h>
using namespace std;
int numberOfArithmeticSlices(vector<int>& nums){
	int n=static_cast<int>(nums.size());
	if(n<3) return 0;
	vector<int> dp(n,0);
	dp[0]=0,dp[1]=0;
	for(int i=2;i<n;++i){
		if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
			dp[i]=dp[i-1]+1;
		}
	}
	return accumulate(dp.begin(),dp.end(),0);
}

int main()
{
return 0;
}
