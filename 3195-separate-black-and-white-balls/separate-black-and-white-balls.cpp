class Solution {
public:
    long long minimumSteps(string s) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        long long swap = 0;
        int black = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') swap += (long long) black;
            else black++;
        }
        return swap;
    }
};