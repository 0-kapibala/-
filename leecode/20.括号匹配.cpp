#include <bits/stdc++.h>
using namespace std;
bool isValid(string s){
	stack<char> st;
	for(int i=0;i<static_cast<int>(s.length());++i){
		if(s[i]=='['||s[i]=='{'||s[i]=='('){
			st.push(s[i]);continue;
		}else if(st.empty()){
			return false;
		}else{
			char c=st.top();
			if((c=='{'&&s[i]=='}')||(c=='['&&s[i]==']')||(c=='('&&s[i]==')')){
				st.pop();
			}else{
				return false;
			}
		}
	}
	return st.empty();
}
int main()
{
return 0;
}
