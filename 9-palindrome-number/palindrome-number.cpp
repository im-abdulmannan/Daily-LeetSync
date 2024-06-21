class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0)
        {
            return false;
        }

        long rev = 0;
        int y = x;

        while(y)
        {
            rev = rev * 10 + y % 10;
            y = y / 10;
        }

        return rev == x;
    }
};