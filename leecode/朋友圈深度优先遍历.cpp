#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& friends,int i,vector<bool>& visited){
	visited[i]=true;
	for(int k= 0;k<static_cast<int>(friends.size());++k){
		if(friends[i][k]==1&&!visited[k]){
			dfs(friends,k,visited);
		}
	}
}


int findCircleNum(vector<vector<int>>& friends){
	int n=static_cast<int>(friends.size());
	int count=0;
	vector<bool> visited(n,false);
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(friends,i,visited);
			++count;
		}
	}
	return count;
}



int main()
{
return 0;
}
