#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (!str) return;

        int spaces = 0;
        int char_num = 0;
        for (int i = 0; str[i]!='\0'; i++){
            char_num ++;
            if (str[i] == ' ') spaces++;
        }

        int len = char_num + spaces*2;
        if (len+1 < length) return;
        char * pw = str+len;
        char * pr = str+char_num;
        while(true){
            if (*pr == ' '){
                *(pw--) = '0';
                *(pw--) = '2';
                *(pw--) = '%';
            } else {
                *(pw--) = *pr;
            }
            if (pr != str) pr--;
            else break;
        }
	}
};





int main()
{
		Solution s;

		char * sstr = "hello world!";
		char * str = new char(14);
		cout<<strlen(sstr)<<" | | "<<strlen(str)<<endl;
		for (int i=0; i<strlen(sstr); i++){
			str[i] = sstr[i];
		}
		cout<<strlen(sstr)<<" | | "<<strlen(str)<<endl;

		cout<<str<<endl;
		s.replaceSpace(str, 14);
		cout<<str<<endl;
}

