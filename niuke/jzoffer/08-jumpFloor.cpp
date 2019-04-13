#include <iostream>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
		if (number <= 2) return number;
		return jumpFloor(number-1)+jumpFloor(number-2);		
    }
};

int main()
{
		Solution s;
		for (int i=0; i<10; i++)
				cout<<s.jumpFloor(i)<<endl;

		return 0;
}
