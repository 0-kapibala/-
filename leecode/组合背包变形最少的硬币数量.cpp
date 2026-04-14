#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount){
	if (coins.empty()) return -1;
	vector<int> dp(amount+1,amount+2);
	dp[0]=0;
	for(int j=1;j<=amount;++j){
		for(const int&  coin:coins){
			if(j>=coin){
				dp[j]=min(dp[j],dp[j-coin]+1);
			}
		}
	}
	return dp[amount]==amount+2?-1:dp[amount];
}
int main()
{
return 0;
}
