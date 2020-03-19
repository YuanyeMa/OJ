//按照指定规则对输入的字符串进行处理。
//详细描述：	
//	将输入的两个字符串合并。
//	对合并后的字符串进行排序，要求为：下标为奇数的字符和下标为偶数的字符分别从小到大排序。这里的下标意思是字符在字符串中的位置。
//	对排序后的字符串进行操作，如果字符为‘0’——‘9’或者‘A’——‘F’或者‘a’——‘f’，则对他们所代表的16进制的数进行BIT倒序的操作，并转换为相应的大写字符。如字符为‘4’，为0100b，则翻转后为0010b，也就是2。转换后的字符为‘2’； 如字符为‘7’，为0111b，则翻转后为1110b，也就是e。转换后的字符为大写‘E’。
//	
//	
//举例：输入str1为"dec"，str2为"fab"，合并为“decfab”，分别对“dca”和“efb”进行排序，排序后为“abcedf”，转换后为“5D37BF”
//接口设计及说明：
//	
//	/*
//	 *
//	 * 功能:字符串处理
//	 *
//	 * 输入:两个字符串,需要异常处理
//	 *
//	 * 输出:合并处理后的字符串，具体要求参考文档
//	 *
//	 * 返回:无
//	 *
//	 * */
//	
//	void ProcessString(char* str1,char *str2,char * strOutput)	
//	{
//	}
//
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int bit_rev(int n)
{
	int res=0;
	int cnt = 4;
	while (cnt--) {
		res = (res<<1) | (n&1);
		n>>=1;
	}
	return res;
}

void str_sort(char * str, int size)
{
	for (int i=0; i<size; i++) {
		for (int j=i+2; j<size; j=j+2) {
			if (str[i]>str[j]) {
				char t = str[i];
				str[i] = str[j];
				str[j] = t;
			}
		}
	}
	//return str;
}

void ProcessString(char* str1,char *str2,char * strOutput)
{
	strcpy(strOutput, str1);
	strcat(strOutput, str2);
        int len = strlen(strOutput);       

	str_sort(strOutput, len);
        
	for (int i=0; i<len; i++) {
		int x=0;
		if (strOutput[i]>='0' && strOutput[i]<='9')
			x = strOutput[i]-'0';
		else if (strOutput[i]>='a' && strOutput[i]<='f')
			x = strOutput[i]-'a'+10;
		else if (strOutput[i]>='A' && strOutput[i]<='F') 
			x = strOutput[i]-'A'+10;
		else {
			continue;
		}
        
		int res = bit_rev(x);
        
		if (res >= 10)
			strOutput[i] = (res-10)+'A';
		else 
			strOutput[i] = res+'0';
	}
	strOutput[len] = '\0';
}       



int main()
{
	string str1, str2;
	cin>>str1>>str2;
	char result[str1.size()+str2.size()+1];
	char word1[str1.size()];
	char word2[str2.size()];

	strcpy(word1, str1.c_str());
	strcpy(word2, str2.c_str());

	ProcessString(word1, word2, result);
	cout<<result<<endl;
	return 0;
}
