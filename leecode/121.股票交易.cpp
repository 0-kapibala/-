#include <bits/stdc++.h>
using namespace std;
int maxprofit(vector<int>& prices){
	int sell=0,buy=INT_MIN;
	for(int i=0;i<static_cast<int>(prices.size());++i){
		buy=max(buy,-prices[i]);
		sell=max(sell,buy+prices[i]);
	}
	return sell;
}
int main()
{
return 0;
}
