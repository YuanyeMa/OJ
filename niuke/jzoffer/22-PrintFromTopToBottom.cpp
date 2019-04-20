#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	TreeNode(int val): val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
		vector<int> PrintFromTopToBottom(TreeNode * root) {
			vector<int> res;
			if (!root) return res;

			deque<TreeNode *> dq(0);
			dq.push_back(root);

			while(!dq.empty()) {
				TreeNode * p = dq.front();
				dq.pop_front();
				if (p) {
					res.push_back(p->val);
					dq.push_back(p->left);
					dq.push_back(p->right);
				}
			}
			return res;
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
	// create a binary tree
	int array[10] = {1, 2,'#', 4, 5, '#', 7, 8, 9, 10};
	vector<int> v(array, array+10);
	TreeNode * root = create_binary_tree(v);
	cout<<"binary tree : ";
	travel_binary_tree(root);
	cout<<endl;
	// Solution
	Solution s;
	vector<int> res = s.PrintFromTopToBottom(root);
	// print vector	
	for (auto it=res.begin(); it!=res.end(); it++) {
		cout<<*it<<" ";
	}
	cout<<endl;

	return 0;
}
