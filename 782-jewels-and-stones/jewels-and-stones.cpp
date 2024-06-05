class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> js(jewels.begin(), jewels.end());
        int sum = 0;

        for (auto stone : stones) {
            if (js.find(stone) != js.end()) {
                sum++;
            }
        }

        return sum;
    }
};