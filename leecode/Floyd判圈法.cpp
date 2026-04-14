#include <bits/stdc++.h>
using namespace std;


struct ListNode {
int val;
ListNode *next;
ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head){
	ListNode *slow=head,ListNode *fast=head;
	do{
		if (!fast || !fast->next)  return nullptr;
		fast=fast->next->next;
		slow=slow->next;
	}while(fast!=slow);
	fast=head;
	while(fast!=slow){
		fast=fast->next;
		slow=slow->next;
	}
	return fast;
}
int main()
{
return 0;
}
