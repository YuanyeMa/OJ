class Solution {
public:
    int fib(int N) {
        int sl[35];
        sl[0] = 0;
        sl[1] = 1;
        for(int i=2; i<=N; i++)
            sl[i] = sl[i-1] + sl[i-2];
        return sl[N];
    }
};
