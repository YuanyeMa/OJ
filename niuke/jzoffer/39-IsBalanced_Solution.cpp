class Solution {
private:
    bool IsBalanced(TreeNode *pRoot, int * depth)
    {
        if (pRoot == NULL) {
            *depth = 0;
            return true;
        }
        int left, right;
        if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right)) {
            int diff = left-right;
            if (diff<=1 && diff>=-1) {
                *depth = 1 + (left > right ? left : right);
                return true;
            }
        }
        return false;
    }
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return IsBalanced(pRoot, &depth);
    }
};
