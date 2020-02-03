/*题目描述
 * •连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
 * •长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
 *
 * 输入描述:
 * 	连续输入字符串(输入2次,每个字符串长度小于100)
 *
 * 输出描述:
 * 	输出到长度为8的新字符串数
 *
 *
 * 输入
 * 	abc
 * 	123456789
 *
 * 输出
 * 	abc00000
 * 	12345678
 * 	90000000
 * */

#include <iostream>
#include <string>

using namespace std;

void show(string str)
{
	int len = str.size();
	if (len==0)
		return;

	len = len%8==0?len:((len/8)+1)*8;

	int count = 0;
	for (auto it=str.begin(); it!=str.end(); it++,count++) {
		if (count!=0 && count%8 == 0)
			cout<<endl;
		cout<<*it;
	}
	while (count++<len)
		cout<<0;
	cout<<endl;

}

int main()
{
	string str1;
	string str2;
	cin>>str1;
	cin>>str2;
	
	show(str1);
	show(str2);
	
	return 0;
}
