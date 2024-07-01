class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxWindow = 0;
        unordered_set<int> charSet;
        int prev = 0;

        for(int i = 0; i < s.length(); i++) {
            if(charSet.count(s[i]) == 0)
            {
                charSet.insert(s[i]);
                maxWindow = max(maxWindow, i - prev + 1);
            }
            else
            {
                while(charSet.count(s[i]) != 0) {
                    charSet.erase(s[prev]);
                    prev+=1;
                }
                charSet.insert(s[i]);
            }
        }

        return maxWindow;
    }
};