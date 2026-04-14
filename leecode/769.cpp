#include <bits/stdc++.h>
using namespace std;
int maxChunksToSorted(vector<int>& arr){
	int chunks=0,cur_max=0;
	for(int i=0;i<static_cast<int>(arr.size());++i){
		cur_max=max(cur_max,arr[i]);
		if(cur_max==i){
			++chunks;
		}
	}
	return chunks;
}
int main()
{
return 0;
}
