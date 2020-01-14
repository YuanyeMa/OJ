#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
	int len = data.size();
	if ( len==0 )
		return ;
	int temp = data[0];
	for (int i=1; i<len; i++) {
		temp ^= data[i];
	}
	if (temp) {
		int index = 0;
		while ((temp&1) == 0){
			temp = temp>>1;
			index++;
		}
		int temp1 = 0, temp2 = 0;
		for (int i=0; i<len; i++) {
			if ( data[i] & (1<<index) ) {
				temp1 ^= data[i];
			} else {
				temp2 ^= data[i];
			}
		}
		*num1 = temp1;
		*num2 = temp2;
	}
    }
};

int main()
{
	int array[] = {2, 4, 3, 6, 3, 2, 5, 5};
	vector<int> data(array, array+8);
	Solution s;
	int result1, result2;
	s.FindNumsAppearOnce(data, &result1, &result2);
	cout<<result1<<endl;
	cout<<result2<<endl;
	return 0;
}
