#include <bits/stdc++.h>
using namespace std;




int findContentchildren(vector<int>& children,vector<int>& cookies){
	sort(children.begin(),children.end());
	sort(cookies.begin(),cookies.end());
	int child=0,cookie=0;
	while(child<children.size()&&cookie<cookies.size()){
		if(children[child]<=cookies[cookie]) ++child;
		++cookie;
	}
	return child;
}

int main()
{
return 0;
}
