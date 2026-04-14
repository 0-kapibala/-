#include <bits/stdc++.h>
using namespace std;
vector<int> findDisappearedNumbers(vector<int>& nums){
	vector<int> ans;
	for(const int& num:nums){
		int p=abs(num)-1;
		if(nums[p]>0)
		nums[p]=-nums[p];
	}
	for(int i=0;i<static_cast<int>(nums.size());++i){
		if(nums[i]>0){
			ans.push_back(i+1);
		}
	}
	return ans;
}
int main()
{
return 0;
}
