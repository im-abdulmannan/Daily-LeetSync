class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, bool> mp;
        int count = 0;
        
        for(const string& str : arr) {
            if(mp.find(str) != mp.end()) {
                mp[str] = false;
            } else {
                mp[str] = true;
            }
        }

        for(const auto& it : arr) {
            if(mp[it]) {
                count++;
                if(count == k) return it;
            }
        }

        return "";
    }
};