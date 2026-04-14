#include <bits/stdc++.h>
using namespace std;
int hammingDistance(int x, int y){
	int n=x^y,ans=0;
	while(n){
		ans+=n&1;
		n>>=1;
	}
	return ans;
}

int main()
{
return 0;
}
