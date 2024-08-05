class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(!visited[i][j] && grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        int maxTime = 0;
        while(!q.empty()) {
            pair<pair<int, int>, int> orange = q.front();
            int row = orange.first.first;
            int col = orange.first.second;
            int time = orange.second;
            maxTime = max(maxTime, time);
            grid[row][col] = 2;

            if(row != 0 && !visited[row - 1][col] && grid[row - 1][col] == 1) {
                visited[row - 1][col] = true;
                q.push({{row - 1, col}, time+1});
            }

            if(row != grid.size() - 1 && !visited[row + 1][col] && grid[row + 1][col] == 1) {
                visited[row + 1][col] = true;
                q.push({{row + 1, col}, time+1});
            }

            if(col != 0 && !visited[row][col - 1] && grid[row][col - 1] == 1) {
                visited[row][col - 1] = true;
                q.push({{row, col - 1}, time+1});
            }

            if(col != grid[0].size() - 1 && !visited[row][col + 1] && grid[row][col + 1] == 1) {
                visited[row][col + 1] = true;
                q.push({{row, col + 1}, time+1});
            }
            q.pop();
        }

        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1) return -1;
        

        return maxTime;
    }
};