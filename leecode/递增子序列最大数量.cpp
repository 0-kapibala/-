#include <bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>& nums){
	int n=static_cast<int>(nums.size()),max_nums=0;
	if(n<=1) return n;
	vector<int> dp(n,1);
	for(int i=0;i<n;++i){
		for(int j=0;j<i;++j){
			if(dp[i]>dp[j]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		max_nums=max(dp[i],max_nums);
	}
	return max_nums;
}
int _lengthOfLIS(vector<int>& nums){
	int n=static_cast<int>(nums.size());
	if(n<=1) return n;
	vector<int> dp;
	dp.push_back(nums[0]);
	for(int i=1;i<n;++i){
		if(dp.back()<nums[i]){
			dp.push_back(nums[i]);
		}else{
			auto itr=lower_bound(dp.begin(),dp.end(),nums[i]);
			*itr=nums[i];
		}
	}
	return dp.size();
}
int main()
{
return 0;
}
