#define ll long long
class Solution {
public:
    int chalkReplacer(vector<int>& chalks, int k) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        ll totalRequiredChalk = 0;
        for(int chalk : chalks) {
            totalRequiredChalk += chalk;
        }

        int extraChalks = k % totalRequiredChalk;

        for(int i = 0; i < chalks.size(); i++) {
            if(extraChalks < chalks[i]) return i;
            extraChalks -= chalks[i];
        }

        return 0;
    }
};