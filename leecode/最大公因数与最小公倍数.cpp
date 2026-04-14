#include <bits/stdc++.h>
using namespace std;
int get_greatest_common_divisor(int a,int b){
	return b == 0 ? a : gcd(b, a% b);
}
int get_least_common_multiple(int a,int b){
	return a*b/get_greatest_common_divisor(a,b);
}

int xGCD(int a, int b, int &x, int &y) {
	if (!b) {
	x = 1, y = 0;
	return a;
	}
	int x1, y1, gcd = xGCD(b, a % b, x1, y1);
	x = y1, y = x1 - (a / b) * y1;
	return gcd;
}//扩展欧几里得
int main()
{
	int m=21,n=14;
    int a =get_greatest_common_divisor(m,n);
    int b =get_least_common_multiple(m,n);
    cout<<a<<'\t'<<b<<endl;
    return 0;
}
