#include <bits/stdc++.h>
using namespace std;
class Solution{
	public:
		bool canFormArray(vector<int>& arr,vector<vector<int>>& pieces){
			int n=arr.size();
			int m=pieces.size();
			sort(pieces.begin(),pieces.end());
			for(int i=0;i<n;){
				int l=0,r=m-1;
				while(l<r){
					int mid=l+r+1>>1;
					if(pieces[mid][0]<=arr[i]) l=mid;
					else r=mid-1;
				}
				int len=pieces[r].size(),idx=0;
				while(idx<len&&pieces[r][idx]==arr[i+idx]) idx++;
				if(idx==len) i+=len;
				else return false ;
				
			}
			return true;
		}
};
int main()
{
return 0;
}
