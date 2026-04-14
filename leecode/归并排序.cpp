#include <bits/stdc++.h>
using namespace std;
void merge_sort(vector<int> &nums, int l, int r, vector<int> &temp){
	if(l+1>=r) return ;
	int m = l+(r-l)/2;
	merge_sort(nums,l,m,temp);
	merge_sort(nums,m,r,temp);
	int p=l, q=m ,i=l;
	while(p<m||q<r){
		if(q>=r||(p<m&&nums[p]<=nums[q])){
			temp[i++]=nums[p++];
		}else{
			temp[i++]=nums[q++];
		}
	}
	for(i=l;i<r;++i){
		nums[i]=temp[i];
	}
}
int main()
{
	vector<int> nums = {3,1,4,1,5,9,2,6};
	vector<int> temp(nums.size()); // 预分配临时空间
	merge_sort(nums, 0, nums.size(), temp);
	// 排序后nums: {1,1,2,3,4,5,6,9}
	for(int i=0;i<8;i++)
		{
			cout<<nums[i]<<'\t';
		}
return 0;
}
