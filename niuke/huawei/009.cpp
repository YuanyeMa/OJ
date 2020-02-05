/*
题目描述
输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。

输入描述:
	输入一个int型整数
输出描述:
	按照从右向左的阅读顺序，返回一个不含重复数字的新的整数
*/

#include <iostream>

using namespace std;

int main()
{	
	long in;
	cin>>in;

	int bitmap[10] = {0};
	long result = 0;

	while(in) {
		int temp = in%10;
		if (bitmap[temp] == 0) {// 数字没有出现过
			result=result*10+temp;
			bitmap[temp] = 1;
		}
		in/=10;
	}	
	cout<<result<<endl;
	return 0;
}

