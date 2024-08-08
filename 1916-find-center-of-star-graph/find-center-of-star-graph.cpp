class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> nodes;

        for (auto edge : edges) {
            if (!nodes.insert(edge[0]).second)
                return edge[0];

            if (!nodes.insert(edge[1]).second)
                return edge[1];
        }

        return -1;
    }
};
