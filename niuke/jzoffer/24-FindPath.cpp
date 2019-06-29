#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
vector<vector<int> > result;
vector<int> tmp;

public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
	if(!root) return result;
	
	tmp.push_back(root->val);
	if((expectNumber - root->val) == 0 && !root->left && !root->right){
		result.push_back(tmp);
	}
	FindPath(root->left, expectNumber - root->val);
	FindPath(root->right, expectNumber - root->val);
	
	tmp.pop_back();
	return result;
    }
};

int main()
{	
	TreeNode A1(1);
	TreeNode A2(2);
	TreeNode A3(3);
	TreeNode A4(4);
	TreeNode A5(5);
	TreeNode A6(6);

	A1.left = &A2;
	A1.right = &A3;
	A2.left = &A4;
	A2.right = &A5;
	A4.left = &A6;

	Solution s = Solution();
	vector<vector<int> >ans = s.FindPath(&A1, 8);

	for (auto it=ans.begin(); it != ans.end(); it++){
		for (auto itt = it->begin(); itt != it->end(); itt++)
			cout<<*itt<<" ";
		cout<<endl;
	}
	
	return 0;
}

