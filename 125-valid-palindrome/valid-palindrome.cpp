class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while(l < r) {
            while(!isalnum(s[l]) && l < r) l++;
            while(!isalnum(s[r]) && l < r) r--;

            // cout << s[l] << " : " << s[r] << endl;

            if(tolower(s[l]) != tolower(s[r])) return false;
            l++, r--;
        }

        return true;
    }
};
