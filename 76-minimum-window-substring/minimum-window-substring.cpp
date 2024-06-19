class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(int i = 0; i < t.length(); i++) {
            mp[t[i]]++;
        }

        int l = 0, r= 0;
        int counter = t.length();
        int minStart = 0;
        int minLength = INT_MAX;

        while(r < s.length()) {
            if(mp[s[r]] > 0) {
                counter--;
            }
            mp[s[r]]--;
            r++;

            while(counter == 0) {
                if(r - l < minLength) {
                    minStart = l;
                    minLength = r - l;
                }
                mp[s[l]]++;

                if(mp[s[l]] > 0) counter++;
                l++;
            }
        }

        return (minLength != INT_MAX) ? s.substr(minStart, minLength) : "";
    }
};