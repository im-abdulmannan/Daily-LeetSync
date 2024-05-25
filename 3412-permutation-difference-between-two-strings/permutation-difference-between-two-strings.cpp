class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> h1(26, -1), h2(26, -1);

        for(int i = 0; i < s.length(); i++) {
            h1[s[i] - 'a'] = i;
        }

        for(int i = 0; i < t.length(); i++) {
            h2[t[i] - 'a'] = i;
        }

        int sum = 0;
        for (int i = 0; i < 26; i++) {
            sum += abs(h1[i] - h2[i]);
        }

        return sum;
    }
};