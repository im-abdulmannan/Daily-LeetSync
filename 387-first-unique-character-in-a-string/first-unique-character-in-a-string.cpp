class Solution {
public:
    int firstUniqChar(string s) {
        int map[26] = {0};

        for(char c : s) {
            map[c - 'a'] += 1;
        }

        for(int i = 0; i < s.length(); i++) {
            if(map[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};