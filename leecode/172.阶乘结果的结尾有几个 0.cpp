#include <bits/stdc++.h>
using namespace std;
int trailingZeroes(int n)
{
	return n==0?0:n/5+trailingZeroes(n/5);
}
int main()
{int a=trailingZeroes(12);
cout<<a<<endl;
return 0;
}
