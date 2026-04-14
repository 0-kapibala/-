#include <bits/stdc++.h>
using namespace std;
vector<int> diffWaysToCompute(string input){
	vector<int> ways;
	std::string::size_type i;
	for(i=0;i<input.length();i++){
		char c=input[i];
		if(c=='+'||c=='-'||c=='*'){
			vector<int> left=diffWaysToCompute(input.substr(0,i));
			vector<int> right=diffWaysToCompute(input.substr(i+1));
			for(const int& l:left){
				for(const int& r:right){
					switch (c) {
						case '+':
							ways.push_back(l+r);
							break;
						case '-':
							ways.push_back(l-r);
							break;
						case '*':
							ways.push_back(l*r);
							break;
					}
				}
			}
		}
	}
	if (ways.empty()) ways.push_back(stoi(input));
	return ways;
}
int main()
{
return 0;
}
