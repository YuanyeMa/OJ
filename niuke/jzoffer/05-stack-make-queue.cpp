#include <iostream>
#include <stack>

using namespace std;


class Solution
{
public:
    void push(int node) {
		 // 1. 将stack1 全部pop push进stack2
			while(!stack1.empty()){
					stack2.push(stack1.top());
					stack1.pop();
			}
		 // 2. 将node push进stack 1
			stack1.push(node);
		 // 3. 将stack2 pop后 push进stack1
			while(!stack2.empty()){
				stack1.push(stack2.top());
				stack2.pop();
			}

    }

    int pop() {
			int val = stack1.top();
			stack1.pop();
			return val;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


int main()
{
	Solution s;
	for (int i=0; i<10; i++){
			s.push(i);
	}
	
	int i = 10;
	while (i--){
			int x = s.pop();
			cout<<x<<endl;
	}
}


