/*
题目描述
写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。（多组同时输入 ）

输入描述:
输入一个十六进制的数值字符串。

输出描述:
输出该数值的十进制字符串。
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
        string str;
        while(cin>>str) {
            int len = str.size();
            int result = 0;
            if (len==0)
                    cout<<result<<endl;

            auto it=str.end()-1;
            int q = 0;
            for ( ; it!=str.begin()+1; it--, q++) {
                    int temp = 0;
                    if (*it>='0' && *it<='9') {
                            temp = *it-'0';
                    } else if (*it>='A' && *it<='F') {
                            temp = *it-'A'+10;
                    } 
                    result += temp*pow(16, q);
            }
            cout<<result<<endl;
        }

        return 0;
}

