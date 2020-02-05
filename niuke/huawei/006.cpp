/*
题目描述
功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）
最后一个数后面也要有空格

详细描述：
	函数接口说明：
		public String getResult(long ulDataInput)
	输入参数：
		long ulDataInput：输入的正整数
	返回值：
		String
*/

#include <iostream>
#include <string>

using namespace std;

int getZ(long h)
{
	for (long i=2; i<=h; i++) {
		if (h%i == 0)
			return i;
	}
}


string getResult(long ulDataInput) 
{
	string s;
	while(ulDataInput != 1) {
		int temp = getZ(ulDataInput);
		s+=to_string(temp)+' '; // c++11提供的全局的函数 std::to_string(int val) 此外还有std::stoi(str_dec, &z)函数
		ulDataInput /= temp;
	}
	return s;
}

int main()
{
	long input=0;
	cin>>input;
	cout<<getResult(input)<<endl;

	return 0;
}
