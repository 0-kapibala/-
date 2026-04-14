#include <bits/stdc++.h>
using namespace std;
void back_tracking(vector<vector<int>> &ans,vector<int> &comb,int &count,int pos,int n,int k){
	if(count==k){
		ans.push_back(comb);
		return;
	}
	for(int i=pos;i<=n;i++){
		comb[count++]=i;
		back_tracking(ans,comb,count,i+1,n,k);
		--count;
	}
}
int main()
{
return 0;
}
