class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c, int sum) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() ||
            grid[r][c] == 0) {
            return sum;
        }

        int temp = grid[r][c];
        grid[r][c] = 0;

        sum += temp;

        int maxSum = sum;
        maxSum = max(maxSum, dfs(grid, r + 1, c, sum));
        maxSum = max(maxSum, dfs(grid, r - 1, c, sum));
        maxSum = max(maxSum, dfs(grid, r, c + 1, sum));
        maxSum = max(maxSum, dfs(grid, r, c - 1, sum));

        grid[r][c] = temp;

        return maxSum;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maximum = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    maximum = max(maximum, dfs(grid, i, j, 0));
                }
            }
        }

        return maximum;
    }
};
