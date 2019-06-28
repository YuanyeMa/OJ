#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<int> result;	
	
	if (rows == 0 && cols == 0)
		return result;

	int left = 0, right = cols-1, top = 0, bottom = rows-1;	

	while(left <= right && top <= bottom)
	{
		// -> to right
		for (int i=left; i<=right; i++)
			result.push_back(matrix[top][i]);

		// |v down
		for (int i=top+1; i<=bottom;  i++)
			result.push_back(matrix[i][right]);

		// <- back left
		if (top != bottom)
			for (int i=right-1; i>=left; i--)
				result.push_back(matrix[bottom][i]);

		// |^ up
		if (left != right)
			for(int i=bottom-1; i>top; i--)
				result.push_back(matrix[i][left]);
		top ++;		
		bottom --;
		left ++;
		right --;
	}
	return result;
    }
};

int main()
{
	vector<vector<int> > matrix;
	int index=1;
	for (int i=0; i<4; i++)
	{	
		vector<int> t;
		for (int j=0; j<1; j++)
			t.push_back(index++);
		matrix.push_back(t);
	}
	
	for (auto it=matrix.begin(); it!=matrix.end(); it++)
	{
		for (auto itt=(*it).begin(); itt!=(*it).end(); itt++)
			cout<<*itt<<" ";
		cout<<endl;
	}
	cout<<"------------------------"<<endl;
	Solution s;
	vector<int> r = s.printMatrix(matrix);
	for(auto it=r.begin(); it!=r.end(); it++)
		cout<<" "<<*it;
	cout<<endl;

	return 0;
}

