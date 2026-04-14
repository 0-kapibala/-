#include <bits/stdc++.h>
using namespace std;
int maxProfitUnlimited(vector<int> prices){
	int max_profit=0;
	for(int i=0;i<static_cast<int>(prices.size())-1;++i){
		if(prices[i]<prices[i+1]){
			max_profit+=prices[i+1]-prices[i];
		}
	}
	return max_profit;
}
int maxprofit_more(vector<int>& prices,int k){
	int n=prices.size();
	if(n<2) return 0;
	if(k>=n){
		return maxProfitUnlimited(prices);
	}
	vector<int> sell(k+1,0), buy(k + 1, INT_MIN);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k;++j){
			buy[j]=max(buy[j],sell[j-1]-prices[i]);
			sell[j]=max(buy[j]+prices[i],sell[j]);
		}
	}
	return sell[k];
}

int main()
{
return 0;
}
