class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n - 2;

        vector<vector<int>> result(m, vector<int> (m, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                result[i][j] = helper(grid, i, j);
            }
        }

        return result;
    }

    int helper(vector<vector<int>>& grid, int i, int j) {
        int max_element = 0;

        for(int r = i; r < i+3; r++) {
            for(int c = j; c < j+3; c++) {
                max_element = max(max_element, grid[r][c]);
            }
        }

        return max_element;
    }
};