#include <iostream>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
  		if (base == 0) return 0;
		if (exponent == 0) return 1;

		int res = 1;
		double base_b = base;
		int x = exponent>0?exponent:(-exponent);
		while (x) {
			if (x&1)  res *= base_b;
			base_b *= base_b;
			x>>=1;
		}	
		return (exponent)>0? res: 1.0/(res);
    }
};

int main()
{
		Solution s;
		cout<<" 2^3 : "<<s.Power(2, 3)<<endl;
		cout<<" 2^-3 : "<<s.Power(2, -3)<<endl;

		return 0;
}

