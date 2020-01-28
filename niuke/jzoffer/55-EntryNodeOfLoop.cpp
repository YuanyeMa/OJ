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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
	if (NULL == pHead)
		return NULL;

	ListNode * fast, * slow;
	slow = pHead;
	fast = pHead->next;
	while (slow!=fast && fast!=NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	if (slow == fast){
		// 计算环中节点个数 n
		int n = 1;
		fast = slow->next;
		while (slow != fast) {
			fast = fast->next;
			n++;
		}
		// 让一个指针先向先走n步
		fast = pHead;
		slow = pHead;
		for (int i=0; i<n; i++) {
			fast = fast->next;
		}
		// 两个指针一起向前移动
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return fast;
	} else 
		return NULL;
    }
};

int main()
{
	ListNode * phead = new ListNode(0);
	ListNode p1 = ListNode(1);
	phead->next = &p1;

	delete phead;
	return 0;
}
