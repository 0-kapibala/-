#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<string>& words){
	unordered_map<int,int> hashmap;
	int ans=0;
	for(const string& word:words){
		int mask=0,size=word.size();
		for(const char& c:word){
			mask|=1<<(c-'a');
		}
		hashmap[mask]=max(hashmap[mask],size);
		for(const auto& [h_mask,h_len]:hashmap){
			if(!(mask&h_mask)){
				ans=max(ans,h_len*size);
			}
		}
	}
	return ans;
}

int main()
{
return 0;
}
