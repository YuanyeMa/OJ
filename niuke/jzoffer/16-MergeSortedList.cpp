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

// 第一版本
//class Solution {
//public:
//		ListNode * Merge(ListNode * pHead1, ListNode * pHead2) {
//				ListNode * res = NULL;
//				if (!pHead1) return pHead2;
//				if (!pHead2) return pHead1;
//
//				ListNode * res_t = res;
//				ListNode * p = NULL;
//				while(pHead1!=NULL &&  pHead2!=NULL) {
//					if (pHead1->val > pHead2->val) {
//							p = pHead2;
//							pHead2 = pHead2->next;
//					} else {
//							p = pHead1;
//							pHead1 = pHead1->next;
//					}
//					p->next = NULL;
//
//					if (!res) {
//						res = p;
//						res_t = res;
//					} else {
//						res_t->next = p;
//						res_t = res_t->next;
//					}
//				}
//				while(pHead1){
//					res_t->next = pHead1;
//					pHead1 = pHead1->next;
//					res_t->next->next = NULL;
//					res_t = res_t->next;
//				}
//				while(pHead2){
//					res_t->next = pHead2;
//					pHead2 = pHead2->next;
//					res_t->next->next = NULL;
//					res_t = res_t->next;
//				}
//
//				return res;
//		}
//};

// 简化版本
class Solution{
public:
		ListNode * Merge(ListNode * pHead1, ListNode * pHead2){
			ListNode * res = new ListNode(-1);
			ListNode * p = res;

			while(pHead1 && pHead2){
				if (pHead1->val >= pHead2->val){
					p->next = pHead2;
					pHead2 = pHead2->next;
				} else {
					p->next = pHead1;
					pHead1 = pHead1->next;
				}
				p = p->next;
			}
			p->next = pHead1?pHead1:pHead2;
			return res->next;
		}
};

int main()
{
		// 创建两个链表
		struct ListNode * head1 = NULL;
		struct ListNode * tail1 = head1;

		struct ListNode * head2 = NULL;
		struct ListNode * tail2 = head2;

		//for (int i=0; i<10; i+=2){
		//	if (head1 == NULL) {
		//			head1 = new ListNode(i);
		//			tail1 = head1;
		//			continue;
		//	}
		//	tail1->next = new ListNode(i);
		//	tail1 =  tail1->next;
		//}

		for (int i=1; i<10; i+=2){
			if (head2 == NULL) {
					head2 = new ListNode(i);
					tail2 = head2;
					continue;
			}
			tail2->next = new ListNode(i);
			tail2 =  tail2->next;
		}


		// 展示链表内容
		cout<<" list 1 :"<<endl;
		for (struct ListNode * p = head1; p!=NULL; p=p->next){
			cout<<p->val<<endl;
		}
		cout<<" list 2 :"<<endl;
		for (struct ListNode * p = head2; p!=NULL; p=p->next){
			cout<<p->val<<endl;
		}

		// 查找倒数第k个节点
		Solution s;
		struct ListNode * res = s.Merge(head1, head2);
		if (res == NULL) cout<<"nothing find"<<endl;
		else {
			cout<<" result :"<<endl;
			for (struct ListNode * p = res; p!=NULL; p=p->next){
				cout<<p->val<<endl;
		}
		}
		
		return 0;
}
