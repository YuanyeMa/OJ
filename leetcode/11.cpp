class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int len = height.size();
        int l = 0, r = len-1;
        while (l < r) {
            //cout<<min(height[l], height[r])*(l-r)<<endl;
            maxA = max(maxA, min(height[l], height[r])*(r-l));
            if (height[l] > height[r])
                r--;
            else 
                l++;
        }
        return maxA;
    }
};
