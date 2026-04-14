#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> ratings){
	int n=ratings.size();
	if(n<2) return size;
	vector<int> num(size, 1);
	for(int i=1;i<n;++i){
		if(num[i]>nums[i-1]){
			num[i]=num[i-1]+1;
		}
	}
	for(int i=n-1;i>0;--i){
			if(num[i]<nums[i-1]){
				num[i]=max{num[i]+1,num[i-1]};
			}
		}
		return accumulate(num.begin(), num.end(), 0);
}


int main()
{
return 0;
}
