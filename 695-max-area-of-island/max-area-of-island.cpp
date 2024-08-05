class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if(row < 0 || row >= grid.size() ||
           col < 0 || col >= grid[0].size() ||
           grid[row][col] == 0
        ) return 0;

        grid[row][col] = 0;

        int size = 1;
        size += dfs(grid, row + 1, col);
        size += dfs(grid, row - 1, col);
        size += dfs(grid, row, col + 1);
        size += dfs(grid, row, col - 1);

        return size;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int area = dfs(grid, i, j);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};