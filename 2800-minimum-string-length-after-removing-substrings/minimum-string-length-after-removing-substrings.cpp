class Solution {
public:
    int minLength(string s) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        stack<char> stk;

        for(int i = 0; i < s.length(); i++) {
            char curr_char = s[i];

            if(stk.empty()) {
                stk.push(curr_char);
                continue;
            }

            if(curr_char == 'B' && stk.top() == 'A') stk.pop();
            else if(curr_char == 'D' && stk.top() == 'C') stk.pop();
            else stk.push(curr_char);
        }

        return stk.size();
    }
};