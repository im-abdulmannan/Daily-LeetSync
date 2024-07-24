class Solution {
public:
    int countWays(int n, vector<int>& dp) {
        if(n <= 2) return n;

        if(dp[n] != 0) return dp[n];

        dp[n] = countWays(n - 1, dp) + countWays(n - 2, dp);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        return countWays(n, dp); 
    }
};