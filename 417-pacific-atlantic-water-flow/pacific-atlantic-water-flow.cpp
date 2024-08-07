class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> to_pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> to_atlantic(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++) {
            dfs(heights, to_pacific, i, 0);
        }

        for(int j = 0; j < cols; j++) {
            dfs(heights, to_pacific, 0, j);
        }

        for(int i = 0; i < rows; i++) {
            dfs(heights, to_atlantic, i, cols - 1);
        }

        for(int j = 0; j < cols; j++) {
            dfs(heights, to_atlantic, rows - 1, j);
        }

        vector<vector<int>> result;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(to_pacific[i][j] && to_atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& to_reach, int row, int col) {
        if(to_reach[row][col]) return;
        to_reach[row][col] = true;

        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto direction : directions) {
            int x = row + direction[0], y = col + direction[1];
            if(x < 0 || y < 0 || x >= rows || y >= cols || heights[row][col] > heights[x][y]) continue;
            dfs(heights, to_reach, x, y);
        }
    }
};