class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        vector<int> freq(k, 0);
        for(auto num : arr) {
            int rem = num % k;
            if(rem < 0) rem += k;
            freq[rem]++;
        }
        if(freq[0] % 2 != 0) {
            return false;
        }
        for(int i = 1; i <= k / 2; i++) {
            if(freq[i] != freq[k - i]) return false;
        }

        return true;
    }
};