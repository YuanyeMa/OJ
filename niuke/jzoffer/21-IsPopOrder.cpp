#include <iostream>
#include <stack>

using namespaces std;

class Solution {
private:
stack<int> stackData;

public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
	int size = pushV.size();
 	if(size == 0) return false;

	for (int i=0, j=0; i<size; i++)
	{
		stackData.push(pushV[i]);
		while(j<popV.size() && stackData.top() == popV[j])
		{
			stackData.pop();
			j++;
		}
	}       
	return stackData.empty();
    }
};


int main()
{
	return 0;
}
