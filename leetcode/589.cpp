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
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == NULL) 
            return result;
        
        stack<Node *> st;
        st.push(root);
        while(!st.empty()) {
            Node * p = st.top();
            st.pop();
            
            result.push_back(p->val);
            int len = (p->children).size();
            for(int i=len-1; i>=0; i--)
                if ((p->children)[i] != NULL)
                    st.push((p->children)[i]);
        }
        return result;
    }
};
