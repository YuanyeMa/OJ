//题目描述
//	若两个正整数的和为素数，则这两个正整数称之为“素数伴侣”，如2和5、6和13，它们能应用于通信加密。现在密码学会请你设计一个程序，从已有的N（N为偶数）个正整数中挑选出若干对组成“素数伴侣”，挑选方案多种多样，例如有4个正整数：2，5，6，13，如果将5和6分为一组中只能得到一组“素数伴侣”，而将2和5、6和13编组将得到两组“素数伴侣”，能组成“素数伴侣”最多的方案称为“最佳方案”，当然密码学会希望你寻找出“最佳方案”。
//
//输入:
//	有一个正偶数N（N≤100），表示待挑选的自然数的个数。后面给出具体的数字，范围为[2,30000]。
//
//输出:
//	输出一个整数K，表示你求得的“最佳方案”组成“素数伴侣”的对数。
//
// 
//
//输入描述:
//	1 输入一个正偶数n
//	2 输入n个整数
//
//输出描述:
//	求得的“最佳方案”组成“素数伴侣”的对数。
//
//示例1
//输入
//	4
//	2 5 6 13
//输出
//	2
//
//	匈牙利最大匹配算法 - https://www.ghostwarlock.com/posts/2729/#%E4%BB%A3%E7%A0%81%E5%AE%9E%E7%8E%B0
//	https://www.bilibili.com/video/av14223723?from=search&seid=10489513529649124043
#include <iostream>

using namespace std;

bool is_prime(int n)
{
	if (n<=1)
		return false;
	for (int i=2; i*i<=n; i++) {
		if (n%i == 0)
			return false;
		else 
			continue;
	}
	return true;
}

int main()
{
	int n;
	int nums[105];
	int dp[105]={0};
	
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>nums[i];
	}


	return 0;
}