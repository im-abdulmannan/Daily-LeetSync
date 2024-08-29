class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int grp = 0;

        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(stones, visited, i);
                grp += 1;
            }
        }

        return n - grp;
    }

    void dfs(vector<vector<int>>& stones, vector<bool>& visited, int idx) {
        visited[idx] = true;
        for(int i = 0; i < stones.size(); i++) {
            if(!visited[i]) {
                if(stones[idx][0] == stones[i][0]) dfs(stones, visited, i);
                if(stones[idx][1] == stones[i][1]) dfs(stones, visited, i);
            }
        }
    }
};