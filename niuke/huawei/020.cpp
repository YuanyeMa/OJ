//题目描述
//密码要求:
//1.长度超过8位
//2.包括大小写字母.数字.其它符号,以上四种至少三种
//3.不能有相同长度超2的子串重复

//说明:长度超过2的子串

//输入描述:
//一组或多组长度超过2的子符串。每组占一行
//输出描述:
//如果符合要求输出：OK，否则输出NG

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string passwd;
	while(cin>>passwd) {
		int count[4]={0}; // 0: A; 1: a; 2:1; 3:&
		if (passwd.size()<=8)
			goto NG;
		for (auto it=passwd.begin(); it!=passwd.end(); it++) {
			if (*it >='0' && *it<='9')
				count[2] = 1;
			else if (*it >='a' && *it<='z')
				count[1] = 1;
			else if (*it >='A' && *it<='Z')
				count[0] = 1;
			else
				count[3] = 1;
		}
		if (count[0] + count[1] + count[2] + count[3] < 3)
			goto NG;

		for (int i=0; i<=passwd.size()-6; i++) {
			for (int j=i+3; j<=passwd.size()-3; j++) {
				if (passwd.substr(i, 3) == passwd.substr(j, 3)) 
					goto NG;
			}
		}
		cout<<"OK"<<endl;
		continue;
NG:
		cout<<"NG"<<endl;
	}
}

