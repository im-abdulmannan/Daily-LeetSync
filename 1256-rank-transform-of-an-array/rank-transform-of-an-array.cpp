class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        unordered_map<int, int> rank;
        vector<int> sortedArray = arr;
        
        sort(sortedArray.begin(), sortedArray.end());
        sortedArray.erase(unique(sortedArray.begin(), sortedArray.end()), sortedArray.end());

        for(int i = 0; i < sortedArray.size(); i++) {
            rank[sortedArray[i]] = i + 1;
        }

        for(int i = 0; i < arr.size(); i++) {
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};