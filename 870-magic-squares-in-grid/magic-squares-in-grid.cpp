class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        vector<int> count(10, 0);
        for(int i = row; i < row + 3; i++) {
            for(int j = col; j < col + 3; j++) {
                int num = grid[i][j];
                if(num < 1 || num > 9 || count[num] > 0) return false;
                count[num]++;
            }
        }

        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        
        for(int r = row; r < row + 3; r++) {
            if(sum != grid[r][col] + grid[r][col + 1] + grid[r][col + 2]) return false;
        }

        for(int c = col; c < col + 3; c++) {
            if(sum != grid[row][c] + grid[row+ 1][c] + grid[row+2][c]) return false;
        }

        if(sum != grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2]) return false;
        if(sum != grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2]) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(rows < 3 || cols < 3) return 0;
        int cnt = 0;

        for(int r = 0; r <= rows - 3; r++) {
            for(int c = 0; c <= cols - 3; c++) {
                if(isValid(grid, r, c)) cnt++;
            }
        }

        return cnt;
    }
};