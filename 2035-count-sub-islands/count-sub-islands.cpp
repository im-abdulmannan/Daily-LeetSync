class Solution {
public:
    int r, c;
    const int d[5] = {0, 1, 0, -1, 0};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        r = grid1.size();
        c = grid1[0].size();
        int cnt = 0, mark = 2;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid2[i][j] == 1) cnt += dfs(i, j, mark++, grid1, grid2);
            }
        }

        return cnt;
    }

    bool dfs(int i, int j, int mark, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if (grid1[i][j] != 1) return false;
        grid2[i][j] = mark;
        bool isSub = true;

        for (int a = 0; a < 4; a++) {
            int s = i + d[a], t = j + d[a + 1];
            if (helper(s, t) || grid2[s][t] != 1) continue;
            if (grid1[s][t] != 1) isSub = false;

            if (!dfs(s, t, mark, grid1, grid2)) 
                isSub = false;
        }

        return isSub;
    }

    inline bool helper(int i, int j) {
        return i < 0 || i >= r || j < 0 || j >= c;
    }
};