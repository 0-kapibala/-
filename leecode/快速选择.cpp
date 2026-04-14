#include <bits/stdc++.h>
using namespace std;
int quickselection(vector<int>& nums,int l,int r){
	int i=l+1,j=r;
	while(true){
		while(i<r&&nums[i]<=nums[l]){
			++i;
		}
		while(j>l&&nums[j]>=nums[l]){
			--j;
		}
		if(i>=j){
			break;
		}
		swap(nums[i],nums[j]);
	}
	swap(nums[j],nums[l]);
	return j;
}
int findKthlargest(vector<int>& nums,int k){
	int l=0,r=nums.size()-1,target=nums.size()-k;
	while(l<r){
		int mid=quickselection(nums,l,r);
		if(mid==target){
			return nums[mid];
		}
		if(mid<target){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return nums[l];
}
int main()
{
return 0;
}
