/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归的代码: 268ms
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == NULL)
            return 0;
        if (root->val > R) {
            return rangeSumBST(root->left, L, R);
        } else if (root->val < L) {
            return rangeSumBST(root->right, L, R);
        } else {
            return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        }
    }
};

// 下边迭代的代码执行效率更高：172ms，93.52%, 这两个代码的内存消耗相同
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        queue<TreeNode *> que;
        if (root == NULL)
            return 0;
        else
            que.push(root);
        while(!que.empty()) {
            TreeNode * p = que.front();
            que.pop();
            if (p == NULL) {
                continue;
            }
            if(p->val>= L && p->val<=R) {
                sum+=p->val;
                que.push(p->left);
                que.push(p->right);
            } else if (p->val > R) {
                que.push(p->left);
            } else {
                que.push(p->right);
            }
        }
        return sum;
    }
};
