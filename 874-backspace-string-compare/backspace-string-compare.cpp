class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> stk_s, stk_t;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] != '#') {
                stk_s.push(s[i]);
            } else if(!stk_s.empty()) {
                stk_s.pop();
            }
        }

        for(int i = 0; i < t.length(); i++) {
            if(t[i] != '#') {
                stk_t.push(t[i]);
            } else if(!stk_t.empty()){
                stk_t.pop();
            }
        }

        return stk_s == stk_t;
    }
};