class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, unordered_set<string>& visited) {
        if(row < 0 || row >= grid.size() ||
           col < 0 || col >= grid[0].size() ||
           grid[row][col] == 0
        ) return 0;

        string pos = to_string(row) + ':' + to_string(col);
        if(visited.count(pos)) return 0;
        visited.insert(pos);

        int size = 1;
        size += dfs(grid, row + 1, col, visited);
        size += dfs(grid, row - 1, col, visited);
        size += dfs(grid, row, col + 1, visited);
        size += dfs(grid, row, col - 1, visited);

        return size;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<string> visited;

        int maxArea = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int area = dfs(grid, i, j, visited);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};