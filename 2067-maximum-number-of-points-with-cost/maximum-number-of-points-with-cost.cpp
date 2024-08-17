class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();
        vector<long long> dp(cols, 0);

        for(int c = 0; c < cols; c++) {
            dp[c] = points[0][c];
        }

        for(int r = 1; r < rows; r++) {
            vector<long long> leftMax(cols, 0), rightMax(cols, 0);
            vector<long long> newDp(cols, 0);

            leftMax[0] = dp[0];
            for(int c = 1; c < cols; c++) {
                leftMax[c] = max(leftMax[c - 1], dp[c] + c);
            }

            rightMax[cols - 1] = dp[cols - 1] - (cols - 1);
            for(int c = cols - 2; c >= 0; c--) {
                rightMax[c] = max(rightMax[c + 1], dp[c] - c);
            }

            for(int n = 0; n < cols; n++) {
                newDp[n] = max(leftMax[n] - n, rightMax[n] + n) + points[r][n];
            }

            dp = newDp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};