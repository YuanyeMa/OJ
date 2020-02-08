/*
题目描述
请解析IP地址和对应的掩码，进行分类识别。要求按照A/B/C/D/E类地址归类，不合法的地址和掩码单独归类。
所有的IP地址划分为 A,B,C,D,E五类
A类地址1.0.0.0~126.255.255.255;
B类地址128.0.0.0~191.255.255.255;
C类地址192.0.0.0~223.255.255.255;
D类地址224.0.0.0~239.255.255.255；
E类地址240.0.0.0~255.255.255.255

私网IP范围是：
10.0.0.0～10.255.255.255
172.16.0.0～172.31.255.255
192.168.0.0～192.168.255.255

子网掩码为二进制下前面是连续的1，然后全是0。（例如：255.255.255.32就是一个非法的掩码）

输入描述:
多行字符串。每行一个IP地址和掩码，用~隔开。

输出描述:
统计A、B、C、D、E、错误IP地址或错误掩码、私有IP的个数，之间以空格隔开。
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_num(char a)
{
	if (a>='0' && a<='9') 
		return true;
	else 
		return false;
}

bool str_is_valid(string str) 
{
	int dots = 0;
	for (auto it=str.begin(); it!=str.end(); it++) {
		if (it == str.begin() ) {
			if ( !is_num(*it) )
				return false;
			else
				continue;
		}
		
		if (is_num(*it)) {
			continue;
		} else if (*it=='.' && is_num(*(it-1)) && is_num(*(it+1)) ) {
			dots++;
			continue;
		}
			
	}
	if (dots == 3)
		return true;
	else 
		return false;
}

vector<int> string2int(string str)
{
	vector<int> res;
	int nums = 0;
	for (auto it=str.begin(); it!=str.end(); it++) {
		if (*it != '.') {
			nums = nums*10+(*it)-'0';
		} else {
			res.push_back(nums);
			nums = 0;
		}
	}
	res.push_back(nums);
	return res;
}

bool mask_is_valid(string mask)
{
	if (!str_is_valid(mask))
		return false;

	bool is_255 = true;

	vector<int> nums = string2int(mask);
	if (nums.size() != 4)
		return false;

	for (auto it=nums.begin(); it!=nums.end(); it++) {
		if (*it<0 || *it>255)
			return false;
		if (is_255 && *it == 255) 
			continue;
		else if (*it==254 || *it==252 || *it==248 || *it==240 ||\
			 *it==224 || *it==192 || *it==128 || *it==0) {
			if (is_255) {		
				is_255 = false;
				continue;
			} else if (*it != 0) {
				return false; 
			}
		} else {
			return false;
		}
	}
	if (is_255)
		return false;
	return true;
}

bool ip_is_valid(string str) 
{
	if (str_is_valid(str))
		return true;
	else 
		return false;
}

int main()
{
	freopen("ip.in", "r", stdin);
	//freopen("ip.out", "w", stdout);

	int cnt_a = 0;
	int cnt_b = 0;
	int cnt_c = 0;
	int cnt_d = 0;
	int cnt_e = 0;
	int cnt_error = 0;
	int cnt_pri = 0;

	string tmp;
	
	while (cin>>tmp) {
		string::size_type pos = tmp.find('~');
		if (pos != tmp.npos) {
			string mask = tmp.substr(pos+1, tmp.size()-pos);
			string ip = tmp.substr(0, pos);
			if ( mask_is_valid(mask) ) {
				if (!ip_is_valid(ip)) {
					cnt_error++;
					//goto show;
					continue;
				}

				vector<int> ip_vec = string2int(ip);
				if (ip_vec.size() != 4) {
					cnt_error++;
					//goto show;
					continue;
				}
				bool ff=false;
				for (int i=0; i<4; i++) {
					if (ip_vec[i]<0 && ip_vec[i]>255) {
						ff = true;
						break;
					}
				}	
				if (ff) {
					cnt_error++;
					//goto show;
					continue;
				}

				if (ip_vec[0]>=1 && ip_vec[0]<=126) {
					cnt_a++;
					if (ip_vec[0] == 10)
						cnt_pri++;
				} else if (ip_vec[0]>=128 && ip_vec[0]<=191) {
					cnt_b++;
					if (ip_vec[0]==172 && ip_vec[1]>=16 && ip_vec[1]<=32)
						cnt_pri++;
				} else if (ip_vec[0]>=192 && ip_vec[0]<=223) {
					cnt_c++;
					if (ip_vec[0] == 192 && ip_vec[1]==168)
						cnt_pri++; 
				} else if (ip_vec[0]>=224 && ip_vec[0]<=239 ) {
					cnt_d++;
				} else if (ip_vec[0]>=240 && ip_vec[0]<=255) {
					cnt_e++;	
				} /*else {
					// 添上此处的cnt_error++不能通过用例，系统认为0.x.x.x为正确的ip
					cnt_error++;
					goto show;
				}*/
			} else {
				cnt_error++;
//show:
				//cout<<cnt_error<<" "<<ip<<" "<<mask<<endl;
			}
		}
	}
	cout<<cnt_a<<" "<<cnt_b<<" "<<cnt_c<<" "<<cnt_d<<" "<<cnt_e<<" "<<cnt_error<<" "<<cnt_pri<<endl;
	return 0;
}

