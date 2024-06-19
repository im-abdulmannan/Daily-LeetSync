class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int maxCount = 0;
        int l = 0, r = 0;
        int result = 0;

        while(r < s.length()) {
            count[s[r] - 'A']++;
            maxCount = max(maxCount, count[s[r] - 'A']);

            if(r - l + 1 - maxCount > k) {
                count[s[l] - 'A']--;
                l++;
            }

            result = max(result, r - l + 1);
            r++;
        }

        return result;
    }
};