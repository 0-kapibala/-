#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>>& matrix){
	int n=matrix.size()-1,temp=0;
	for(int i=0;i<=n/2;++i){
		for(int j;j<n-i;++j){
			temp=matrix[n-j][i];
			matrix[n-j][i]=matrix[n-i][n-j];
			matrix[n-i][n-j]=matrix[j][n-i];
			matrix[j][n-i]=matrix[i][j];
			matrix[i][j]=temp;
		}
	}
}
int main()
{
return 0;
}
