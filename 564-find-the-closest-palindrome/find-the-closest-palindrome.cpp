#define ll long long
#define s string
class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        if(len == 1) return to_string(stoi(n) - 1);

        vector<ll> candidates;
        candidates.push_back(pow(10, len - 1) - 1);
        candidates.push_back(pow(10, len) + 1);
        ll prefix = stoll(n.substr(0, (len + 1) / 2));
        for(int i = -1; i <= 1; i++) {
            s p = to_string(prefix + i);
            s candidate = p + s(p.rbegin()+(len%2), p.rend());
            candidates.push_back(stoll(candidate));
        }

        ll num = stoll(n);
        ll closet = -1;

        for(ll cand : candidates) {
            if(cand==num) continue;
            if(cand == -1 || abs(cand - num) < abs(closet - num) ||
               (abs(cand - num) == abs(closet-num) && cand < closet)) {
                closet = cand;
               }
        }

        return to_string(closet);
    }
};