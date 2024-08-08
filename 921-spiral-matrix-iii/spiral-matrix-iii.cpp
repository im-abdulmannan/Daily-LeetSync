class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans(rows * cols, vector<int>(2));
        int i = 0;
        ans[i++] = {rStart, cStart};
        int len = 0;
        int d = 0;
        int direction[] = {0, 1, 0, -1, 0};
        while (i < rows * cols) {
            if (d == 0 || d == 2) {
                len++;
            }

            for (int k = 0; k < len; k++) {
                rStart += direction[d];
                cStart += direction[d + 1];

                if (rStart < rows && rStart >= 0 && cStart < cols &&
                    cStart >= 0) {
                    ans[i++] = {rStart, cStart};
                }
            }

            d = ++d % 4;
        }

        return ans;
    }
};