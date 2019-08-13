#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int l_j = J.length();
	int l_s = S.length();

	int num = 0;
	
	for(int i=0; i<l_j; i++) {
		for(int j=0; j<l_s; j++) {
			if ( S[j] == J[i] )
				num++;
		}
	}

	return num;
    }
};

int main()
{
	string J = "z";
	string S = "aAAbbbb";

	Solution s;
	cout<<s.numJewelsInStones(J, S)<<endl;
	return 0;
}
