#include <iostream>
#include <vector>
#include <deque>
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
	bool isSametree(TreeNode * p1, TreeNode * p2)
	{
		if (!p2) return true;
		if (!p1) return false;
		// 下边注释的代码在leetcode 的572题 测试通过，牛客网的OJ系统和leetcode的不同
		//if (p1==NULL || p2==NULL) {
		//	if (NULL==p1 && NULL==p2) return true;
		//	else return false;
		//} 

		if (p1->val == p2->val) {
			return isSametree(p1->left, p2->left) && isSametree(p1->right, p2->right);
		} else return false;
	}

public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		if (NULL==pRoot1 || NULL==pRoot2) return false;
		return isSametree(pRoot1, pRoot2) || 
				isSametree(pRoot1->left, pRoot2) ||
				isSametree(pRoot1->right, pRoot2);
    }
};

TreeNode * create_binary_tree(vector<int> & array)
{
	int len = array.size();
	if (!len) return NULL;

	deque<TreeNode*> dq(0);

	int index = 0;
	TreeNode * root = new TreeNode(array[index++]);
	dq.push_back(root);
	
	while(!dq.empty() && index<len) {
		TreeNode * p = dq.front();
		dq.pop_front();
		if (index<len && array[index]!='#') {
			p->left = new TreeNode(array[index]);
			dq.push_back(p->left);
		} else p->left = NULL;
		index++;
		if (index<len && array[index]!='#') {
			p->right = new TreeNode(array[index]);
			dq.push_back(p->right);
		} else p->right = NULL;
		index++;
	}
	return root;
}

void travel_binary_tree(TreeNode * pRoot)
{		
		if (!pRoot) return;
		cout<<pRoot->val<<" ";
		travel_binary_tree(pRoot->left);
		travel_binary_tree(pRoot->right);
}

int main()
{
		//int array1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		//int array1[5] = {3, 4, 5, 1, 2};
		//int array1[11] = {8, 8, 7, 9, 2, '#', '#', '#', '#', 4, 7};
		int array1[9] = {8, '#', 8, '#', 9, '#', 2, '#', 5 };
		vector<int> v1(array1, array1+9);
		cout<<"pRoot1 : ";
		for (int i=0; i<v1.size(); i++)
				cout<<" "<<v1[i];
		cout<<endl;

		//int array2[3] = {4, 8, 9};
		//int array2[3] = {8, 9, 2};
		int array2[5] = {8, '#', 9, 3, 2};
		vector<int> v2(array2, array2+5);
		cout<<"pRoot2 : ";
		for (int i=0; i<v2.size(); i++)
				cout<<" "<<v2[i];
		cout<<endl;
		// create two binary trees
		TreeNode * pRoot1 = create_binary_tree(v1);
		TreeNode * pRoot2 = create_binary_tree(v2);

		// travel binary tree
		cout<<"pRoot1 pre travel :";
		travel_binary_tree(pRoot1);
		cout<<endl;
		cout<<"pRoot2 pre travel :";
		travel_binary_tree(pRoot2);
		cout<<endl;

		// search child tree
		Solution s;
		if (s.HasSubtree(pRoot1, pRoot2))
			cout<<"pRoot1 have pRoot2"<<endl;
		else
			cout<<"pRoot1 don`t have pRoot2"<<endl;

		return 0;
}

