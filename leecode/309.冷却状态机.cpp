#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices){
	int n=prices.size();
	if(!n) return 0;
	
	vector<int> buy(n),sell(n),s1(n),s2(n);
	buy[0]=-prices[0];
	s1[0]=buy[0];
	sell[0]=0;
	s2[0]=sell[0];
	for(int i=1;i<n;++i){
		buy[i]=s2[i-1]-prices[i];
		s1[i]=max(buy[i-1],s1[i-1]);
		sell[i]=max(buy[i-1],s1[i-1])+prices[i];
		s2[i]=max(sell[i-1],s2[i-1]);
	}
	return max(sell[n-1],s2[n-1]);
}
int main()
{
return 0;
}
