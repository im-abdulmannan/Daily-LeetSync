class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }

            // if(n != 1 && n % 2 != 0) return false;
        while(n % 2 == 0) {
            n /= 2;
        }

        // if (n != 1) return false;
        // return true;

        return n == 1;
    }
};