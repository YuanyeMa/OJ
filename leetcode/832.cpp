class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto it=A.begin(); it!=A.end(); it++) {
            int left = 0;
            int right =  (*it).size()-1;
            while (left < right ) {
                int tmp = 1-(*it)[left];
                (*it)[left] = 1-(*it)[right];
                (*it)[right] = tmp;
                left++;
                right--;
            }
            if (left == right)
                (*it)[left] = 1-(*it)[left];
        }
        return A;
    }
};
