#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int f(int n, int m)
    {
	    if (n==1) 
		return 0;
	    else 
		return (f(n-1, m) + m)%n;
    }

    int LastRemaining_Solution(int n, int m)
    {
	if (n<1 || m<1)
		return -1;
 	// 暴力法
	//vector<int> numbers;
	//for (int i=0; i<n; i++)
	//	numbers.push_back(i);
        //
	//int cnt_n = 0;
	//int cnt_m = -1;
        //
	//while (numbers.size() > 1) {
	//	for (cnt_m=1; cnt_m<m; cnt_m++) {
	//		cnt_n++;
	//		cnt_n %= numbers.size();
	//	}
	//	numbers.erase(numbers.begin()+cnt_n);
	//}
	//return numbers[0];
	
	// 推理公式
	//  f(n, m) = (f(n-1, m) + m) % n;
	//  https://blog.csdn.net/fuxuemingzhu/article/details/79702974
	// return f(n, m);  //递归写法
	// 非递归写法
	if (n==1)
		return 0;
	else {
		int temp = 0;
		for (int i=2; i<=n; i++) 
			temp = (temp+m)%i;
		return temp;
	}
    }
};

// 约瑟夫环 Joseph Ring

//样例输入
//1 10
//8 5
//6 6
//
//样例输出
//0
//2
//3

int main()
{
	Solution s;
	cout<<s.LastRemaining_Solution(1, 10)<<endl;
	cout<<s.LastRemaining_Solution(8, 5)<<endl;
	cout<<s.LastRemaining_Solution(6, 6)<<endl;
	return 0;
}

