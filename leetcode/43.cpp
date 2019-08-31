class Solution {
public:
    string multiply(string num1, string num2) {
            int len1 = num1.length();
            int len2 = num2.length();
        
            if ((len1 == 1 && num1[0] == '0') || (len2 == 1 && num2[0] == '0'))
                return "0";
            
            string result(len1+len2, '0');
            
            for (int i=len2-1; i>=0; i--) {
                int n = num2[i]-'0';
                for (int j=len1-1; j>=0; j--) {
                    int m = num1[j]-'0';
                    
                    int ji = m*n+(result[len1-1-i+len2-1-j]-'0');
                    result[len1-1-i+len2-1-j] = (ji%10)+'0';
                    result[len1-1-i+len2-1-j+1] = (ji/10 + (result[len1-1-i+len2-1-j+1]-'0'))+'0';
                }
            }
            string ans;
            bool flag = false;
            int size = result.length()-1;
            for (int k=size; k>=0; k--) {
                if (result[k] != '0') 
                    flag = true;
                if (flag)
                    ans.push_back(result[k]);
            }
            return ans;
    }
};


// 抄网友一个很牛逼的代码

class Solution {
public:
    string multiply(string num1, string num2) {
            int len1 = num1.length();
            int len2 = num2.length();
        
            string result(len1+len2, '0');
            
            for (int i=len2-1; i>=0; i--) {
                for (int j=len1-1; j>=0; j--) {
                    int temp = result[i+j+1]-'0' + (num1[j]-'0')*(num2[i]-'0');
                    result[i+j+1] = temp%10 + '0';
                    result[i+j] += temp/10;
                }
            }
            int len = len1+len2;
            for (int i=0; i<len; i++){
                if (result[i] != '0')
                    return result.substr(i);
            }
            return "0";
    }
};
