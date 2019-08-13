#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        int len = address.length();
	string result(len+3*2, '\0');
	
	for (int i=0, j=0; i<len; i++) {
		if (address[i] != '.') {
			result[j++] = address[i];
		} else {
			result[j++] = '[';
			result[j++] = '.';
			result[j++] = ']';
		}
		cout<<result<<endl;
	}
	return result;
    }
};

int main()
{
	string addr = "192.168.1.1";
	Solution s;
	cout<<s.defangIPaddr(addr)<<endl;
	return 0;
}
