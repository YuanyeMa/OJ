class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0; // ˮƽ�����λ��
        int v = 0; // ��ֱ�����λ��
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
