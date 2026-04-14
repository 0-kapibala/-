#include <bits/stdc++.h>
using namespace std;
int my_sqrt(int a){
	if(a==0) return 0;
	
	int l=1,r=a,mid,_sqrt;
	
	while(l<=r){
		mid=l+(r-l)/2;
		_sqrt=a/mid;
		if(_sqrt==mid)
		return _sqrt;
		else if(_sqrt<mid)
		{
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return r;
}
int my_Sqrt(int a) {
long x = a;
while (x * x > a) {
x = (x + a / x) / 2;
}
return x;
}
int main()
{
	int n=8;
	int m=my_sqrt(n);
	int t=my_Sqrt(n);
	cout<<m<<'\t'<<t<<endl;
return 0;
}
