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

		vector<vector<int> > array;


		for (int i=0; i<5; i++){
				vector<int> tt;
				for (int j=0; j<5; j++) {
						tt.push_back(martix[i][j]);
				}
				array.push_back(tt);
		}
		
		for (int i=0; i<5; i++){
			for (int j=0; j<5; j++)
				cout<<array[i][j]<<" ";
			cout<<endl;
		}
		
		Solution s;
		if (s.Find(7, array)) cout<<"7 find"<<endl;
		else cout<<"nothing find"<<endl;

		return 0;
}
