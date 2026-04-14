#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
	int p=m--+n---1;
	while(m>=0&&n>=0)
	{
		if(nums2[n]>nums1[m])
		{
			nums1[p--]=nums2[n--];
		}
		else if(nums2[n]<nums1[m])
		{
			nums1[p--]=nums1[m--];
		}
	}
	while(n>=0){
		nums1[p--]=nums2[n--];
	}
}
int main()
{
return 0;
}
