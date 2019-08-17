/*
腾讯经典五十题：二叉搜索树的最近公共祖先
*/

#include <iostream>
#include <vector>

using namespace std;


Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 这道题是我自己想复杂了
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * pointer = root;
        while (root) {
            if (p->val > pointer->val && q->val > pointer->val)
                pointer = pointer->right;
            else if (p->val < pointer->val && q->val < pointer->val)
                pointer = pointer->left;
            else 
                return pointer;
        }
        return root;
    }
};

int main()
{
	return 0;
}
