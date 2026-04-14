#include <bits/stdc++.h>
using namespace std;
bool search(vector<int>& nums, int target){
	int _start=0,_end=nums.size()-1,mid;
	while(_start<=_end){
		mid=(_start+_end)/2;
		
		if(nums[mid]==target){
			return true;
		}
		
		if(nums[mid]==nums[_start]){
			++_start;
		}
		else if(nums[mid]<=nums[_end]){
			if(nums[mid]<target&&target<=nums[_end]){
				_start=mid+1;
			}else{
				_end=mid-1;
			}
		}
		else{
			if(nums[_start]<=target&&target<nums[mid]){
				_end=mid-1;
			}else{
				_start=mid+1;
			}
		}
	}
	return false;
}
int main()
{
return 0;
}
