class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";

        int lengthOfString1 = str1.length();
        int lengthOfString2 = str2.length();

        int totalGcdLength = gcd(lengthOfString1, lengthOfString2);
        return str1.substr(0, totalGcdLength);
    }

    int gcd(int lengthOfString1, int lengthOfString2) {
        if(lengthOfString2 == 0) {
            return lengthOfString1;
        }

        return gcd(lengthOfString2, lengthOfString1 % lengthOfString2);
    }
};