#include <iostream>

using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
	//if (num1 == 0)
	//        return num2;
	//else if (num2 == 0)
	//        return num1;
	//else {
	//        int sum=0;
	//        while (num2) {
	//        	sum = num1 ^ num2;
	//        	num2 = (num1&num2) << 1 ;// 进位值
	//        	num1 = sum;
	//        }
	//}
	//return num1;
    	return num2 ? Add(num1^num2, (num1&num2)<<1) : num1;
    }
};

// 求和相当于求异或，进位相当于按位与再左移一位
int main()
{
	Solution s;
	cout<<s.Add(1, 2)<<endl;
	return 0;
}

