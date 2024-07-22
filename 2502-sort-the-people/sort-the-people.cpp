class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> nameHeightPair;

        for(int i = 0; i < names.size(); i++) {
            nameHeightPair.push_back({heights[i], names[i]});
        }

        sort(nameHeightPair.rbegin(), nameHeightPair.rend());

        for(int i = 0; i < names.size(); i++) {
            names[i] = nameHeightPair[i].second;
        }

        return names;
    }
};