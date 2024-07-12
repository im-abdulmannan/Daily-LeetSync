class Solution {
private:
    void letterCombinationsHelper(string digits, int idx, string combination, vector<string>& keypad, vector<string>& result) {
        if(combination.size() == digits.size()) {
            result.push_back(combination);
            return;
        }

        int digit = digits[idx] - '0';
        string& letters = keypad[digit];
        for (char c : letters) {
            letterCombinationsHelper(digits, idx + 1, combination + c, keypad, result);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;

        letterCombinationsHelper(digits, 0, "", keypad, result);
        return result;
    }
};