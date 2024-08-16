class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0][0];
        int largest = arrays[0].back();
        int maxDist = 0;

        for(int i = 1; i < arrays.size(); i++) {
            maxDist = max(maxDist, abs(arrays[i].back() - smallest));
            maxDist = max(maxDist, abs(largest - arrays[i][0]));
            smallest = min(smallest, arrays[i][0]);
            largest = max(largest, arrays[i].back());
        }

        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        return maxDist;
    }
};