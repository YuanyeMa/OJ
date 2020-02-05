/*
题目描述
数据表记录包含表索引和数值（int范围的整数），请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。

输入描述:
	先输入键值对的个数
	然后输入成对的index和value值，以空格隔开
输出描述:
	输出合并后的键值对（多行）
*/

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, int> table;

	int n;
	cin>>n;
	while(n) {
		int index, value;
		cin>>index>>value;
		if (table.find(index) != table.end()) // 表中已经存在
			table[index] += value;
		else { 
			table[index] = value;
		}
		n--;
	}

	for (auto it=table.begin(); it!=table.end(); it++) {
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}

	return 0;
}
