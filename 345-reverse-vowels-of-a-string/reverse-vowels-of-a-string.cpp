class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;

        while(l < r) {
            while(l < r && !isVowel(tolower(s[l]))) l++;
            while(l < r && !isVowel(tolower(s[r]))) r--;

            swap(s[l], s[r]);
            l++, r--;
        }

        return s;
    }
};