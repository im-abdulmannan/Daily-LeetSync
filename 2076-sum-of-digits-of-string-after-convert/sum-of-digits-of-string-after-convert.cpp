class Solution {
public:
    int getLucky(string s, int k) {
        string ans = "";
        
        for(auto& i : s) {
            ans += to_string(i - 'a' + 1);
        }

        while(k--) {
            int sum = 0;
            for(char c : ans) {
                sum += c - '0';
            }
            ans = to_string(sum);
        }

        return stoi(ans);
    }
};
