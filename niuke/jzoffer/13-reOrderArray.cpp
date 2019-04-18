#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
		void reOrderArray(vector<int> &array){
			int len = array.size();
			for (int i=0; i<len; i++){
				for (int j=0; j<len; j++) {
					if (array[j]%2 == 0 && array[j+1]%2 !=0 ) {
						int temp = array[j];
						array[j] = array[j+1];
						array[j+1] = temp;
					}
				}
			}
		}
};

int main()
{
		int a[7] = {2, 4, 6, 1, 3, 5, 7};
		vector<int> v(a, a+7);
		for(int i=0; i<v.size(); i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
		Solution s;
		s.reOrderArray(v);
		for(int i=0; i<v.size(); i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
		return 0;
}
