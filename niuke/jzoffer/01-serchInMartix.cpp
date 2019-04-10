#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size()!= 0)
        {
            int row = 0;
            int col = array[0].size()-1;
            while(row < array.size() && col >= 0)
            {
                if(array[row][col] == target)
                    return true;
                else if(array[row][col] > target)
                    --col;
                else
                    ++row;
            }
             
        }
        return false;
    }
};

int main()
{	
		int martix[5][5]={{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}, {4, 5, 6, 7, 8}, {5, 6, 7, 8, 9}};

		vector<vector<int> > array(martix, martix+25);

		for (auto i:martix){
				cout<<i<<endl;
				//for(auto j:i)
				//		cout<<j<<" ";
				cout<<endl;
		}

		return 0;
}
