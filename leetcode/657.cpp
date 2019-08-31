class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0; // 水平方向的位移
        int v = 0; // 垂直方向的位移
        for (int i=0; moves[i]!='\0'; i++) {
            if (moves[i] == 'L')
                h++;
            else if (moves[i] == 'R')
                h--;
            else if (moves[i] == 'U')
                v++;
            else 
                v--;
        }
        return h==0 && v==0;
    }
};
