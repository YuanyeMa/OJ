//题目描述
//1、对输入的字符串进行加解密，并输出。
//2加密方法为：
//	当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,如字母a时则替换为B；字母Z时则替换为a；
//	当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0；
//	其他字符不做变化。
//3、解密方法为加密的逆过程。
//
//接口描述：
//    实现接口，每个接口实现1个基本操作：
//
//void Encrypt (char aucPassword[], char aucResult[])：在该函数中实现字符串加密并输出
//说明：
//    1、字符串以\0结尾。
//    2、字符串最长100个字符。     
//
//int unEncrypt (char result[], char password[])：在该函数中实现字符串解密并输出
//说明：
//    1、字符串以\0结尾。
//    2、字符串最长100个字符。
//
//输入描述:
//	输入一串要加密的密码
//	输入一串加过密的密码
//
//输出描述:
//	输出加密后的字符
//	输出解密后的字符
//
//示例1
//输入
//	abcdefg
//	BCDEFGH
//输出
//	BCDEFGH
//	abcdefg
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, password; 
	getline(cin, str);
	getline(cin, password);

	for (auto it=str.begin(); it!=str.end(); it++) {
		if ((*it)>='a' && (*it)<'z') {
			(*it)-=('a'-'A'-1);
		} else if ((*it) == 'z') {
			(*it) = 'A';
		} else if ((*it)>='A' && (*it)<'Z') {
			(*it)+=('a'-'A'+1);
		} else if ((*it) == 'Z') {
			(*it) = 'a';
		} else if ((*it)>='0' && (*it)<'9') {
			(*it)+=1;
		} else if ((*it) == '9') {
			(*it) = '0';
		} else {
			continue;
		}
	}

	for (auto it=password.begin(); it!=password.end(); it++) {
		if ((*it)>'a' && (*it)<='z') {
			(*it)= (*it)-1-('a'-'A');
		} else if ((*it) == 'A') {
			(*it) = 'z';
		} else if ((*it)>'A' && (*it)<='Z') {
			(*it)= (*it)+('a'-'A')-1;
		} else if ((*it) == 'a') {
			(*it) = 'Z';
		} else if ((*it)>'0' && (*it)<='9') {
			(*it)-=1;
		} else if ((*it) == '0') {
			(*it) = '9';
		} else {
			continue;
		}
	}
	cout<<str<<endl;
	cout<<password<<endl;
}
