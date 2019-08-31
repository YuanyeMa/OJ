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
bool  is_traveled(Node * prev, Node * p) 
{
    int len = (p->children).size()-1;
    for (int i=len; i>=0; i--) 
        if ((p->children)[i] != prev)
            return false;
    return true;
              
}
    
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        stack<Node *> st;
        Node * cur = root;
        Node * prev = root;
        st.push(root);
        
        while(!st.empty()) {
            cur = st.top();
            if ( (cur->children).size() == 0 || is_traveled(prev, cur))  {
                // 所有孩子都为NULL 或者 所有孩子已经访问过了则访问该节点
                result.push_back(cur->val);
                prev = cur;
                st.pop();
            } else {
                // 否则 所有孩子入栈
                int len = (cur->children).size()-1;
                for (int i=len; i>=0; i--) 
                    if ((cur->children)[i] != NULL)
                        st.push((cur->children)[i]); 
            }
        }
        return result;
    }
};

// 上边代码没调通，执行超时
class Solution {    
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == NULL)
            return result;
        
        stack< pair<Node *, bool> > st;
        st.push(make_pair(root, false));
        
        Node * cur = root;
        
        while(!st.empty()) {
            auto& node = st.top();
            bool visted = node.second;
            cur = node.first;
            if (visted) {
                // 所有孩子都为NULL 或者 所有孩子已经访问过了则访问该节点
                result.push_back(cur->val);
                st.pop();
            } else {
                // 否则 所有孩子入栈
                int len = (cur->children).size()-1;
                for (int i=len; i>=0; i--) 
                    if ((cur->children)[i] != NULL)
                        st.push(make_pair((cur->children)[i], false));
                node.second = true;
            }
        }
        return result;
    }
};

// 更高效的一种方式是还按照前序的方式访问，最后反转一下前序序列
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>  res;
        if(root == nullptr)
        {
            return res;
        }
        
        stack<Node*> s;
        Node* temp = nullptr;
        
        s.push(root);
        
        while(!s.empty())
        {
            temp = s.top();
            res.push_back(temp->val);
            s.pop();
            
            int k = temp->children.size();
            
            for(int i =0;i<k;i++)
            {
                s.push(temp->children[i]);
            }
            
        }
        
        reverse(res.begin(),res.end());
        
        return res;
         
    }
}; 
