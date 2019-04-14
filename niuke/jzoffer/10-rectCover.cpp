#include <iostream>

using namespace std;

class Solution {
public:
    int rectCover(int number) {
		if (!number) return 0;
		else if (number <=2 ) return number;
		return rectCover(number-1)+rectCover(number-2);
    }
};


int main()
{
	Solution s;
	for (int i=0; i<10; i++){
		cout<<s.rectCover(i)<<endl;
	}
	return 0;
}

