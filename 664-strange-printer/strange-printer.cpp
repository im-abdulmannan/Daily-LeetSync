class Solution {
public:
    int helper(const string& s, int l, int r, vector<vector<int>>& dp) {
        if(l > r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        char firstLetter = s[l];
        int ans = 1 + helper(s, l + 1, r, dp);
        for(int i = l + 1; i <= r; i++) {
            if(s[i] == firstLetter) {
                ans = min(ans, helper(s, l, i - 1, dp) + helper(s, i + 1, r, dp));
            }
        }

        return dp[l][r] = ans;
    }

    int strangePrinter(string s) {
        int n = s.length() - 1;
        vector<vector<int>> dp(n + 1,  vector<int> (n + 1, -1));
        return helper(s, 0, n, dp);
    }
};