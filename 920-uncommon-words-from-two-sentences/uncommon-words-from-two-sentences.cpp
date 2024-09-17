class Solution {
public:
    void frequency(string str, unordered_map<string, int>& um) {
        stringstream s(str);
        string word;
        while (s >> word)
            um[word]++;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> um;
        frequency(s1, um);
        frequency(s2, um);
        vector<string> ans;
        for (auto w : um) {
            if (w.second < 2) {
                ans.push_back(w.first);
            }
        }
        return ans;
    }
};