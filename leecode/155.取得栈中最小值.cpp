#include <bits/stdc++.h>
using namespace std;
class MinStack{
	stack<int> s,min_s;
	public:
		void push(int x){
			s.push(x);
			if(min_s.empty()||x<=min_s.top()){
				min_s.push(x);
			}
		}
		void pop(){
			if(min_s.top()==s.top()&&!min_s.empty()){
				min_s.pop();
			}
			s.pop();
		}
		int top(){
			return s.top();
		}
		int get_min(){
			return min_s.top();
		}
		
};
int main()
{
return 0;
}
