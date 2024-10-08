class Solution {
public:
    int minSwaps(string s) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int size = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '[')
                size++;
            else if (size > 0) 
                size--;
        }
        return (size + 1) / 2;
    }
};