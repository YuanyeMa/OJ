#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool bst(vector<int> sequence, int begin, int end){
        if (sequence.empty() || begin > end) return false;
        if (begin==end) return true;
        int root = sequence[end];
        int i = begin;
        for(; i<end; i++)
            if (root<sequence[i]) break;
        for(int j=i; j<end; j++)
            if (root>sequence[j]) return false;

        bool left = true;
        if (i>begin) left = bst(sequence, begin, i-1);
        bool right = true;
        if (i<(end-1)) right = bst(sequence, i, end-1);

        return left && right;
    }
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return bst(sequence, 0, sequence.size()-1);
    }
};

int main()
{
    // int sequence[]={1, 4, 2, 6, 5, 10, 11, 14, 20, 17, 12, 7};
    // vector<int> seq(sequence, sequence+12);

    int sequence[]={7, 4, 6, 5};
    vector<int> seq(sequence, sequence+4);

    for(auto iter = seq.begin(); iter != seq.end(); iter++)
    {
        cout<<*iter<<" ";        
    }
    cout<<endl;
    Solution s;
    if(s.VerifySquenceOfBST(seq))
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;

    return 0;
}

