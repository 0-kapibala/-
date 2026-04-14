#include <bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums){
	if(nums.size()==0) return 0;
	int n=nums.size();
	vector<int> dp(n+1,0);
	dp[1]=nums[0];
	for(int i=1;i<static_cast<int>(nums.size());i++){
		dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
	}
	return dp[n];
}

int _rob(vector<int>& nums){
	if(nums.size()==0) return 0;
	int pre1=0,pre2=0,cur1;
	for(int i=1;i<static_cast<int>(nums.size());i++){
		cur1=max(nums[i]+pre2,pre1);
		pre2=pre1;
		pre1=cur1;
	}
    return cur1;	
}


int main()
{
return 0;
}
