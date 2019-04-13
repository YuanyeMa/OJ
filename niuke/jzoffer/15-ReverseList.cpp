#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

//递归方法
//class Solution {
//public:
//    ListNode* ReverseList(ListNode* pHead) {
//		if (!pHead) return NULL;
//		if (pHead->next==NULL) return pHead;
//		ListNode * p = ReverseList(pHead->next);
//		pHead->next->next = pHead;
//		pHead->next = NULL;
//		return p;
//    }
//};


//使用栈
class Solution {
public:
		ListNode * ReverseList(ListNode * pHead) {
			if (!pHead) return NULL;
			stack<ListNode *> stak;
			for (ListNode * p=pHead; p!=NULL; p=p->next)
				stak.push(p);

			ListNode * newHead = stak.top();
			ListNode * p  = newHead;
			stak.pop();
			while(!stak.empty()) {
					p->next = stak.top();
					p = p->next;
					p->next = NULL;
					stak.pop();
			}
			return newHead;
		}
};

int main()
{	
	//1. create a list
	ListNode * head = new ListNode(-1);
	ListNode * p = head;
	for (int i=0; i<10; i++){
		p->next = new ListNode(i);
		p = p->next;
	}

	//2. travel the list
	for(p=head->next; p!=NULL; p=p->next)
			cout<<p->val<<endl;
	
	//3. reverse the list
	cout<<"reverse list :"<<endl;
	Solution s;
	ListNode * newHead = s.ReverseList(head->next);
	for(p=newHead; p!=NULL; p=p->next)
			cout<<p->val<<endl;
	

	return 0;
}
