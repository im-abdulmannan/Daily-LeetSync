class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        unordered_map<string, int> prefixMap;

        for(int num : arr1) {
            string strNum = to_string(num);
            string prefix = "";
            for(char ch : strNum) {
                prefix += ch;
                prefixMap[prefix]++;
            }
        }

        int maxi = 0;

        for(int num : arr2) {
            string strNum = to_string(num);
            string prefix = "";
            for(char ch : strNum) {
                prefix += ch;
                if(prefixMap.find(prefix) != prefixMap.end()) {
                    maxi = max(maxi, static_cast<int>(prefix.length()));
                }
            }
        }

        return maxi;
    }
};