class Solution {
public:
    void dfs(vector<vector<int>>& mat, int row, int col, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(auto direction : directions) {
            int x = direction[0] + row, y = direction[1] + col;
            if(x < 0 || x >= m || y < 0 || y >= n || mat[x][y] != 0 || visited[x][y]) continue;
            dfs(mat, x, y, visited);
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(n * 3, vector<int>(n * 3, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '/') {
                    mat[i*3][j*3+2] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3] = 1;
                } else if(grid[i][j] == '\\') {
                    mat[i*3][j*3] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3+2] = 1;
                }
            }
        }

        int count = 0;
        vector<vector<bool>> visited(n*3, vector<bool>(n*3, false));
        for(int i = 0; i < n * 3; i++) {
            for(int j = 0; j < n * 3; j++) {
                if(mat[i][j] == 0 && !visited[i][j]) {
                    count++;
                    dfs(mat, i, j, visited);
                }
            }
        }

        return count;
    }
};