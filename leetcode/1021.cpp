/*
跳过第一个左括号，后边分别记录左边括号和右边括号的个数，
如果左边括号和右边括号个数相等，此时的右括号一定是最外层的，跳过这个右括号。
*/
class Solution {
public:
    string removeOuterParentheses(string S) {
        int l=1, r=0;	// l保存左括号的个数（第一个左括号肯定是外层的，需要跳过因此l从1开始计数） r表示右括号的个数，
        int len = S.size();
        
        string result;
        
        for (int i=1; i<len; i++) {
            if (S[i] == '(') 
                l++;
            else 
                r++;
            if ( l != r) 
                result.push_back(S[i]);
            else { 	// 左括号和右括号个数相等，这时的右括号就是和第一个左括号匹配的外层括号，跳过它。
                i+=1;
                l = 1;
                r = 0;
            }
        }
        return result;
    }
};
