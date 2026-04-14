#include <bits/stdc++.h>
using namespace std;
string convert_base7(int n){
	if(n==0) return "0";
	bool is_negative=n;
	if(!is_negative) n=-n;
	string ans;
	while(n){
		int k=n%7;
		n/=7;
		ans+=to_string(k);
	}
	return (!is_negative)?"-"+ans:ans;
}
int main()
{string a=convert_base7(100);
cout<<a<<endl;
return 0;
}
