#include <bits/stdc++.h>
using namespace std;

int upperbound(vector<int> &nums, int target){
	int l=0,r=nums.size(),mid;
	while(l<r){
		mid=(l+r)/2;
		if(nums[mid]>target){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return l;
}
int lowerbound(vector<int> &nums, int target){
	int l=0,r=nums.size(),mid;
		while(l<r){
			mid=(r+l)/2;
			if(nums[mid]>=target){
				r=mid;
			}else{
				l=mid+1;
			}
		}
	return l;
}
int main()
{
return 0;
}
