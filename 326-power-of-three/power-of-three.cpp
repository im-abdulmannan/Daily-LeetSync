class Solution {
public:
    bool isPowerOfThree(int n) {
        // Edge case
        if (n <= 0)
            return false;

        // Base Case
        if (n == 1)
            return true;

        // Condition 
        if (n > 3 && n % 3 != 0)
            return false;

        return isPowerOfThree(n/3);
    }
};