#include <iostream>

using namespace std;

// 暴力求解方法
class Solution{
public:
    int jumpFloorII(int number) {
        if (!number) return 1;

		int count=0;
		for (int i=1; i<=number; i++)
	        count += jumpFloorII(number-i);
		return count;
    }
};


// 简便方法
//class Solution{
//public:
//    int jumpFloorII(int number) {
//		if (number < 2) return 1;
//		return 2*jumpFloorII(number-1);
//    }
//};

int main()
{
		Solution s;
		for (int i=0; i<10; i++)
				cout<<s.jumpFloorII(i)<<endl;

		return 0;
}
