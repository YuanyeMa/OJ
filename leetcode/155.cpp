class MinStack {
stack<int> st;
stack<int> st_min;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        st.push(x);
        if (st_min.empty())
            st_min.push(x);
        else if (x<=st_min.top())
            st_min.push(x);
    }
    
    void pop() {
        if (st.top() == st_min.top() ) {
            st.pop();
            st_min.pop();
        } else {
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
