#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

// Solution 1 : use deque
// class Solution {
// public:
//     int TreeDepth(TreeNode* pRoot)
//     {
// 		if (!pRoot) return 0;
// 		queue<TreeNode*> q;
// 		TreeNode * tail = pRoot;
// 		int depth = 0;
// 		q.push(pRoot);

// 		while(!q.empty()) {
// 			TreeNode * p = q.front();				
// 			if(p->left) q.push(p->left);
// 			if(p->right) q.push(p->right);
// 			if(p==tail) {
// 				depth++;
// 				tail = q.back();
// 			}
// 			q.pop();
// 		}
// 		return depth;
//     }
// };

//Solution 2: use dfs
class Solution{
public:
	int TreeDepth(TreeNode * pRoot)
	{
		if(!pRoot) return 0;
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return (left>right)?(left+1):(right+1);

	}
};

int main()
{
	TreeNode a1 = TreeNode(1);
	TreeNode a2 = TreeNode(2);
	TreeNode a3 = TreeNode(3);
	TreeNode a4 = TreeNode(4);
	TreeNode a5 = TreeNode(5);
	TreeNode a6 = TreeNode(6);

	a1.left=&a2;
	a1.right=&a3;
	a2.left=&a4;
	a2.right=&a5;
	a4.left=&a6;

	Solution s;
	cout<<s.TreeDepth(&a1)<<endl;

	return 0;
}

