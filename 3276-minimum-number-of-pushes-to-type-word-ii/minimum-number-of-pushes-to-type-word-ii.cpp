class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {0};
        for(char ch : word) {
            freq[ch - 'a']++;
        }

        sort(freq, freq+26);
        int ans = 0;
        for(int sz = 25; sz >= 0 && freq[sz] != 0; sz--) {
            ans += freq[sz] * ((25 - sz) / 8 + 1);
        }

        return ans;
    }
};