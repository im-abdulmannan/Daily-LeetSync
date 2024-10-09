class Solution {
public:
    int minAddToMakeValid(string s) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int open = 0, close = 0;
        for(auto c : s) {
            if(c == '(') open++;
            else {
                if(open > 0) open--;
                else close++;
            }
        }
        return open + close;
    }
};