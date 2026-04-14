#include <bits/stdc++.h>
using namespace std;
void back_tracking(vector<int>  &nums,int level,vector<vector<int>>  &ans){
	if(level==nums.size()-1){
		ans.push_back(nums);
		return ;
	}
	for(int i=level;i<nums.size();i++){
		swap(nums[i],nums[level]);
		back_tracking(nums,level+1,ans);
		swap(nums[i],nums[level]);
	}
}


vector<vector<int>> permute(vector<int> &nums){
	vector<vector<int>> ans;
	back_tracking(nums,0,ans);
	return ans;
}
int main()
{
return 0;
}
