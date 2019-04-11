#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int MOD=10000;
struct Mat{
		int a[2][2];
};

Mat mat_mul(Mat x, Mat y)
{
		Mat res;
		memset(res.a, 0, sizeof(res.a));
		for(int i=0; i<2; i++)
				for(int j=0; j<2; j++)
						for(int k=0; k<2; k++) {
							res.a[i][j] += x.a[i][k] * y.a[k][j];
							res.a[i][j] %= MOD;
						}
		return res;
}

int pow(int n)
{
		Mat c, res;
		memset(res.a, 0, sizeof(res.a));

		c.a[0][0] = 1;
		c.a[0][1] = 1;
		c.a[1][0] = 1;
		c.a[1][1] = 0;

		for (int i=0; i<2; i++) res.a[i][i] = 1;

		while(n){
			if (n&1) res = mat_mul(res, c);
			c = mat_mul(c, c);
			n = n>>1;
		}
		return res.a[0][1];
}


class Solution {
public:
	// 递归解法
    //int Fibonacci(int n) {
	//	if (n<2) return n;
	//	return Fibonacci(n-1) + Fibonacci(n-2);
    //}
	
	// 循环解法
    //int Fibonacci(int n) {
	//		if (n==0) return 0;
	//		else if (n==1) return 1;
	//		int f0 = 0;
	//		int f1 = 1;
	//		int f2 = 0;
	//		for (int i=2; i<=n; i++){
	//			f2 = f0+f1;
	//			f0 = f1;
	//			f1 = f2;
	//		}
	//		return f2;
	//}
	
	// 矩阵解法
	int Fibonacci(int n) {
		return pow(n);
	}
	
};

int main()
{
	Solution s;
	for (int i=0; i<10; i++){
		cout<<s.Fibonacci(i)<<endl;
	}
	return 0;
}
