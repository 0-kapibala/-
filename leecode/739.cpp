#include <bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures){
	int n=temperatures.size();
	vector<int> ans;
	stack<int> indices;
	for(int i=0;i<n;++i){
		while(!indices.empty()){
			int pre_index=indices.top();
			if(temperatures[i]<=temperatures[pre_index]){
				break;
			}
			indices.pop();
			ans[pre_index]=i-pre_index;
		}
		indices.push(i);
	} 
	return ans;
}
int main()
{
return 0;
}
