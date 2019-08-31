class Solution {
bool is_zcs(int num) {
    int x = num;
    while(num) {
        int i = num%10;
        if (i == 0)
            return false;
        if (x%i != 0)
            return false;
        num/=10;
    }
    return true;
}
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i<=right; i++) {
            if (is_zcs(i))
                ans.push_back(i);
        }
        return ans;
    }
};
