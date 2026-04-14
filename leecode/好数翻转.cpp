#include <bits/stdc++.h>
using namespace std;
int prime(int n)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		bool yes=false;
		bool val=true;
		int x=i;
		while(x)
{
	int t=x%10;
	x/=10;
	if(t==2||t==5||t==6||t==9)
	yes=true;
	else if(t==3||t==4||t==7)
	{
		val=false;
	    break;
		}
	}
	if(yes&&val) ans++;
	} 
	return ans;
	
}
int main()
{
    
	return 0;
}
