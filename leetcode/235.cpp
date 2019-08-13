#include <iostream>

using namespace std;
 
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next; 
    }
};

int main()
{
	return 0;
}

// 要删除node但是无法得到node前边节点的指针，因此，将node后边节点的val赋给node-val，然后删除node后边的节点

