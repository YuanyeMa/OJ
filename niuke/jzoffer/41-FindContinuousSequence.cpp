#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
	int begin=1, end=2, mid=(sum+1)/2;
	int temp = begin+end;

	while (begin<mid) {
		while (temp>sum && begin<mid) {
			temp -= begin;
			begin++;
		}
		if (temp == sum) {
			vector<int> sub_res;
			for (int i=begin; i<=end; i++)
				sub_res.push_back(i);
			res.push_back(sub_res);
		}
		end++;
		temp += end;
	}
	return res;
    }
};

int main()
{
	int s=0;
	cin>>s;
	Solution ss;
	vector<vector<int> > result = ss.FindContinuousSequence(s);
	for (auto it=result.begin(); it!=result.end(); it++) {
		for (auto itt=(*it).begin(); itt!=(*it).end(); itt++)
			cout<<*itt<<" ";
		cout<<endl;
	}
	return 0;
}
