#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n){
	if(n<=2) return 0;
	vector<bool> prime(n,true);
	int count=n-2;
	for(int i=2;i<n;i++){
		if(prime[i]){
			for(int j=2*i;j<n;j+=i){
				if(prime[j]){
					prime[j]=false;
					--count;
				}
			}
		}
	}
	return count;
}
int great_countPrimes(int n){
	if(n<=2) return 0;
	vector<bool> prime(n,true);
	int i=3,_sqrt=sqrt(n),count=n/2;
	while(i<=_sqrt){
		for(int j=i*i;j<n;j+=2*i){
			if(prime[j]){
				prime[j]=false;
				--count;
			}
		}
		do{
			i+=2;
		}while(i<=_sqrt&&!prime[i]);
	}
	return count;
}
int main()
{
return 0;
}
