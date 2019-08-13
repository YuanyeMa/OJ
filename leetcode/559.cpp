/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL)
            return 0;
        int max_dep = 0;
        for (auto it = (root->children).begin(); it!= (root->children).end(); it++) {
           max_dep = max(maxDepth (*it), max_dep);
        }
        return max_dep+1;
    }
};
