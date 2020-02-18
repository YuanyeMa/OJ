/*
题目描述
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。

处理： 
1、 记录最多8条错误记录，循环记录，对相同的错误记录（净文件名称和行号完全匹配）只记录一条，错误计数增加；
2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
3、 输入的文件可能带路径，记录文件名称不能带路径。

输入描述:
	一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

输出描述:
	将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：
输入
	E:\V1R2\product\fpgadrive.c   1325
输出
	fpgadrive.c 1325 1
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Error{
public:
	string filename;
	int num_line;
	int cnt;
	Error(string str, int n, int c) : filename(str), num_line(n), cnt(c) {};

	bool operator== (const Error& err)  // for find
	{
		if (err.filename==filename && err.num_line==num_line)
			return true;
		return false;
	}
};

string slove_name(string str)
{
	string ret;
	string::size_type pos = str.rfind("\\");
	if (string::npos == pos) {
		ret = str;
	} else {
		ret = str.substr(pos+1);
	}
	if (ret.size()>16) {
		ret = ret.substr(ret.size()-16);
	}
	return ret;
}

int main()
{
	vector<Error> v_list;
	string filename;
	int num_line;
	while(cin>>filename>>num_line) {
		string name = slove_name(filename);
		vector<Error>::iterator it;
		Error e(name, num_line, 1);
		if ( (it=std::find(v_list.begin(), v_list.end(), e)) != v_list.end() )	{
			(*it).cnt++;
		} else {
			v_list.push_back(e);
		}
	}

	int size = v_list.size();
	int start_index = size-8;
	if (start_index<0) 
		start_index = 0;
	
	for (int i=start_index; i<size; i++) {
		cout<<v_list[i].filename<<" "<<v_list[i].num_line<<" "<<v_list[i].cnt<<endl;
	}
	return 0;
}

