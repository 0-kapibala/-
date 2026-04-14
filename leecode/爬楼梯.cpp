#include <bits/stdc++.h>
using namespace std;
int climbStairs(int n){
	if (n<=2){
		return n;
	}
	vector<int> dp(n+1,1);
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}
int climb_stairs(int n){
	if(n<=2) return n;
	int pre1=2,pre2=1,cur;
	for(int i=2;i<n;++i){
		cur=pre1+pre2;
		pre2=pre1;
		pre1=cur;
	}
	return cur;
}
int main()
{
return 0;
}
