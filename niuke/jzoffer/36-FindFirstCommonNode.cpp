#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL || pHead2 == NULL) return NULL;

        int m = 1;
	for (ListNode *p=pHead1; p!=NULL; p=p->next, m++);
        int n = 1;
	for (ListNode *p=pHead2; p!=NULL; p=p->next, n++);
	
	int k = m>n?(m-n):(n-m);
	
	ListNode *p, *q;
	m>n ? (p=pHead1, q=pHead2) : (p=pHead2,q=pHead1);
	while(k--) p=p->next;
	while(p!=q) {
		p = p->next;
		q = q->next;
	}
	return p;
    }
};

int main()
{
	ListNode l11 = ListNode(1);
	ListNode l12 = ListNode(2);
	ListNode l13 = ListNode(3);
	ListNode l14 = ListNode(4);
	ListNode l15 = ListNode(5);
	ListNode l16 = ListNode(6);

	ListNode l21 = ListNode(11);
	ListNode l22 = ListNode(22);
	ListNode l23 = ListNode(33);
	ListNode l24 = ListNode(44);
	ListNode l25 = ListNode(55);

	l11.next = &l12;
	l12.next = &l13;
	l13.next = &l14;
	l14.next = &l15;
	l15.next = &l16;
	l16.next = NULL;
	
	ListNode * p = &l11;
	while(p != NULL) {
		cout<<p->val<<endl;
		p=p->next;
	}
	
	l21.next = &l22;
	l22.next = &l23;
	l23.next = &l24;
	l24.next = &l25;
	l25.next = &l14;
	

	p = &l21;
	while(p != NULL) {
		cout<<p->val<<endl;
		p = p->next;
	}
	
	Solution s = Solution();
	cout<<s.FindFirstCommonNode(&l11, &l21)->val<<endl;
	return 0;
}
