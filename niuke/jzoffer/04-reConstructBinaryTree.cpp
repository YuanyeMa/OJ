#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
	TreeNode * ReBuildTree(vector<int> pre, int pre_index_begin, int pre_index_end, vector<int>vin, int vin_index_begin, int vin_index_end){
			cout<<"======================"<<endl;
			cout<<"pre_index_begin "<<pre_index_begin<<endl;
			cout<<"pre_index_end "<<pre_index_end<<endl;
			cout<<"vin_index_begin "<<vin_index_begin<<endl;
			cout<<"vin_index_end "<<vin_index_end<<endl;

		if (pre_index_begin >= pre_index_end || vin_index_begin >= vin_index_end) return NULL;

		TreeNode * root = new TreeNode(pre[pre_index_begin]);
		cout<<"-----------------------"<<root->val<<endl;

		int index = vin_index_begin;
		for (; index<vin_index_end; index++){
			if (vin[index] == pre[pre_index_begin]){
				break;
			}
		}
		cout<< index<<endl;
		root->left = ReBuildTree(pre, pre_index_begin+1, pre_index_begin+index-vin_index_begin+1, vin, vin_index_begin, index);
		root->right = ReBuildTree(pre, pre_index_begin+index-vin_index_begin+1, pre_index_end, vin, index+1, vin_index_end);
		return root;
	}

	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
			return ReBuildTree(pre, 0, pre.size(), vin, 0, vin.size());
    }
};

int print_tree(TreeNode * t)
{
		if (t==NULL) {
				cout<<"="<<endl;
				return 0;
		}
		cout<<"left"<<endl;
		print_tree(t->left);
		cout<<"from left"<<endl;
		cout<<" "<<t->val<<" "<<endl; 
		cout<<"right"<<endl;
		print_tree(t->right);
		cout<<"from right"<<endl;
}

int main()
{
		int p[] = {1, 2, 4, 7, 3, 5, 6, 8};
		int v[] = {4, 7, 2, 1, 5, 3, 8, 6};
		vector<int> pre(p, p+8);
		vector<int> vin(v, v+8);

		for (auto i:pre) cout<<i<<endl;
		Solution s;
		TreeNode * root = s.reConstructBinaryTree(pre, vin);
		print_tree(root);

		return 0;
}

