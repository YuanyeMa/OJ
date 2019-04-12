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

// 通过栈来实现
//class Solution {
//public:
//    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//    	if (pListHead == NULL) return NULL;
//		stack<struct ListNode *> stak;
//		for (struct ListNode *p = pListHead; p!=NULL; p=p->next) {
//			stak.push(p);
//		}
//
//		int index = 1;
//		while(!stak.empty() && index!=k) {
//			stak.pop();
//			index++;
//		}
//		return stak.top();
//    }
//};

// 一次遍历实现
class Solution {
public:
		ListNode * FindKthToTail(ListNode * pListHead, unsigned int k) {
			auto fast_p = pListHead;
			auto slow_p = pListHead;
			for (int i=0; i!=k; ++i) {
				if (!fast_p) return NULL;
				else fast_p = fast_p->next;
			}

			while(fast_p) {
				fast_p = fast_p->next;
				slow_p = slow_p->next;
			}
			return slow_p;
		}
};


int main()
{
		// 创建一个链表
		struct ListNode * head = NULL;
		struct ListNode * tail = head;

		for (int i=0; i<10; i++){
			if (head == NULL) {
					head = new ListNode(i);
					tail = head;
					continue;
			}
			tail->next = new ListNode(i);
			tail =  tail->next;
		}

		// 展示链表内容
		for (struct ListNode * p = head; p!=NULL; p=p->next){
			cout<<p->val<<endl;
		}

		// 查找倒数第k个节点
		Solution s;
		struct ListNode * res = s.FindKthToTail(head, 3);
		if (res == NULL) cout<<"nothing find"<<endl;
		else cout<<"result : "<<res->val<<endl;
		
		return 0;
}
