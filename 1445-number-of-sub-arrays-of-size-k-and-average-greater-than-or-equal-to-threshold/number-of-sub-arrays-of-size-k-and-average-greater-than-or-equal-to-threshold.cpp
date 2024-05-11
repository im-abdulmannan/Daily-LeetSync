class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt = 0;
        int sum = 0;
        int length = 0;
        int idx = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            length += 1;
            if (length == k) {
                if ((sum / k) >= threshold) {
                    cnt++;
                }
                length -= 1;
                sum -= arr[idx];
                idx++;
            }
        }

        return cnt;
    }
};