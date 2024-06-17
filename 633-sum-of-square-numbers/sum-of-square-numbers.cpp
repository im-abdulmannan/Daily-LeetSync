class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 2; i * i <= c; i++) {
            if(c % i == 0) {
                int expoCnt = 0;
                while(c % i == 0) {
                    expoCnt++;
                    c /= i;
                }

                if(i % 4 == 3 && expoCnt % 2 != 0) {
                    return false;
                }
            }
        }

        return c % 4 != 3;
    }
};