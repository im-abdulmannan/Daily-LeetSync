class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        set<int> chr;
        for(auto& allow : allowed) {
            chr.insert(allow);
        }

        int ans = 0;
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            int j = 0;
            for(auto& w : word) {
                if(chr.find(w) == chr.end()) {ans -= 1; break;}
            }
            ans+=1;
        }

        return ans;
    }
};