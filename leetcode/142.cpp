/*
	判断链表是否有环，并且找到环的入口。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return NULL;
        ListNode * pFast = head;
        ListNode * pSlow = head;
        while (pFast->next && pFast->next->next) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            if (pFast == pSlow) { // 有环
                ListNode * ptr = head;
                ListNode * ptr1 = pFast; 
                while (ptr != ptr1) {
                    ptr = ptr->next;
                    ptr1 = ptr1->next;
                }
                return ptr;
            }
        }
        return NULL;
    }
};
