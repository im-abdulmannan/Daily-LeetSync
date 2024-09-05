class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

        int m = rolls.size(), sum = 0;
        for (auto roll : rolls) sum += roll;

        int rhs = mean * (n + m);
        rhs -= sum;
        int x = rhs / n, y = rhs % n;
        if (x <= 0 || x > 6) return {};
        if (x == 6 && y > 0) return {};

        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[i] = x;
        for (int i = 0; i < y; i++) ans[i]++;

        return ans;
    }
};