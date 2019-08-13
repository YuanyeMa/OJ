class Solution {
public:
    string toLowerCase(string str) {
        for (int i=0; str[i]!='\0'; i++) {
            if (str[i]>='A' && str[i]<='Z')
                str[i]-= ('A'-'a');
        }
        return str;
    }
};

// 另一种写法：直接使用tolower(str[i])函数
