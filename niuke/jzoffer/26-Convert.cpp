#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
private:
	void ConvertNode(TreeNode * pCurrent, TreeNode ** last)
	{
		if (pCurrent == NULL) return;
		
		if (pCurrent->left != NULL) ConvertNode(pCurrent->left, last);
		pCurrent->left = *last;
		
		if(*last != NULL) (*last)->right = pCurrent;
		(*last) = pCurrent;

		if (pCurrent->right != NULL) ConvertNode(pCurrent->right, last);
	}
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
     	TreeNode * lastNodeInList = NULL; //pointer to the last node in list;
	ConvertNode(pRootOfTree, &lastNodeInList);
	
	TreeNode * pHead = lastNodeInList;
	while (pHead != NULL && pHead->left != NULL)	pHead = pHead->left; 
   
	return pHead;
    }
};

int main()
{	
	TreeNode root = TreeNode(5);
	TreeNode p1 = TreeNode(3);
	TreeNode p2 = TreeNode(2);
	TreeNode p3 = TreeNode(4);
	TreeNode p4 = TreeNode(1);
	TreeNode p5 = TreeNode(7);
	TreeNode p6 = TreeNode(6);
	TreeNode p7 = TreeNode(9);
	TreeNode p8 = TreeNode(8);

	root.left = &p1;
	root.right = &p5;

	p1.left = &p2;
	p2.left = &p4;
	p1.right = &p3;
	p5.left = &p6;
	p5.right = &p7;
	p7.left = &p8;

	Solution s = Solution();

	TreeNode * list = s.Convert(&root);
	
	TreeNode * p = list;
	while(p != NULL) {
		cout<<p->val<<" ";
		p = p->right;
	}
	cout<<endl;

	return 0;
}
