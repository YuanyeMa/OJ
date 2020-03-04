//题目描述
//计算最少出列多少位同学，使得剩下的同学排成合唱队形
//
//说明：
//N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。
//合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，   则他们的身高满足存在i（1<=i<=K）使得T1<T2<......<Ti-1<Ti>Ti+1>......>TK。
//你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
//
//请注意处理多组输入输出！
//
//输入描述:
//整数N
//
//输出描述:
//最少需要几位同学出列
//
//示例1
//输入
//8
//186 186 150 200 160 130 197 200
//输出
//4


// dp数组里的数字表示 每个数在所在队列的人数
// 比如 
//	160这个数字，
//	在递增队列中有2个数150 160（dp1[i]=2）， 
//	在递减队列中有2个数160 130 (dp2[i]=2) ,
// 	则160所在的队列一种有dp1[i]+dp2[i]-1个数字 (160在两个队列中被算了两次，所以减1) 
//	所以最后结果为 n-max(dp1+dp2-1)
#include <iostream>

using namespace std;

int main()
{
	int n;
	int heights[10005], dp1[10005], dp2[10005];
	while (cin>>n) {
		for (int i=0; i<n; i++) {
			cin>>heights[i];
			dp1[i] = 1;
			for (int j=0; j<i; j++) {
				if (heights[i] > heights[j])
					dp1[i] = max(dp1[i], dp1[j]+1);
			}
		}
		for (int i=n-1; i>=0; i--) {
			dp2[i] = 1;
			for (int j=n-1; j>i; j--) {
				if (heights[i] > heights[j])
					dp2[i] = max(dp2[i], dp2[j]+1);
			}
		}
		int max_l=0;
		for (int i=0; i<n; i++) {
			int len = dp1[i]+dp2[i]-1;
			if (len > max_l)
				max_l = len;

		}
		cout<<n-max_l<<endl;
	}
	return 0;
}
