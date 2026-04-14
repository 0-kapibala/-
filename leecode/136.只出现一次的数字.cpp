#include <bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums){
	int e=0;
	for(const int num:nums){
		e^=num;
	}
	return e;
}


int main()
{
return 0;
}
