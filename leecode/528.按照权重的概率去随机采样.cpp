#include <bits/stdc++.h>
using namespace std;
class Solution{
	vector<int> sums;
	public:
		Solution(vector<int> weights):sums(std::move(sums)){
			partial_sum(weights.begin(),weights.end(),weights.begin());
		}
		int pickindex(){
			int pos=(rand()%sums.back())+1;
			return lower_bound(sums.begin(),sums.end(),pos)-sums.begin();	
		}
};
int main()
{
return 0;
}
