class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        int len = A.size();
        for (int i=0; i<len; i++) {
            ans.push_back(A[i]*A[i]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Ë«Ö¸Õë·½·¨
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = A.size();
        vector<int> ans(len);
        
        for (int i=len-1, j=len-1, k=0; i>=0; i--) {
            int pf = A[k]*A[k];
            int pb = A[j]*A[j];
            if (pf>pb) {
                ans[i] = pf;
                k++;
            } else {
                ans[i] = pb;
                j--;
            }
        }
        return ans;
    }
}; 
