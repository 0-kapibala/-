#include <bits/stdc++.h>
using namespace std;
class ListNode {
public:
    int data;
    ListNode* next;


    // 默认构造函数
    ListNode() : data(0), next(nullptr) {}

    // 带参数的构造函数
    ListNode(int value) : data(value), next(nullptr) {}

    // 构造函数，指定数据和下一个节点
    ListNode(int value, ListNode* nextNode) : data(value), next(nextNode) {}

    // 获取数据
    int getData() const { return data; }

    // 获取下一个节点
    ListNode* getNext() const { return next; }

    // 设置下一个节点
    void setNext(ListNode* nextNode) { next = nextNode; }
};
class Solution{
	ListNode* head;
	public:
		Solution(ListNode* n): head(n) {}
		int getrandom(){
			int ans=head->data;
			ListNode* node=head->next;
			
			int i=2;
			while(node){
				if((rand()%i)==0)
				ans=node->data;
				++i;
				node=node->next;
			}
			return ans;
		}
};
int main()
{
return 0;
}
