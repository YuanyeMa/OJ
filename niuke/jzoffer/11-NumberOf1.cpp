#include <iostream>

using namespace std;

// 错误的答案
//class Solution {
//public:
//     int  NumberOf1(int n) {
//         int count = 0;
//		 if (n==0) return 0;
//		 else if(n>0) {
//		 	while(n) {
//				count += (n%2);
//				n>>=1;
//			}
//		 } else {
//		 	n = (-n);
//			int flag = 1;
//			for (int i=1; n!=0; n>>=1, i++){
//				int temp = (n%2?0:1);  // 反码
//				count += (temp+flag)%2;
//				flag = (temp+flag) / 2;
//			}
//		}
//		return count;
//     }
//};


//最优解
class Solution {
public:
     int  NumberOf1(int n) {
        int ans=0;
        while(n)
        {
            ans++;
            n&=n-1;
        }
        return ans;
     }
};


int main()
{
	Solution s;
	cout<<" 11 : "<<s.NumberOf1(11)<<endl;
	cout<<" -11 : "<<s.NumberOf1(-11)<<endl;
	return 0;
}

