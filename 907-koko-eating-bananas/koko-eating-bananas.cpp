class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            int hoursNeeded = 0;

            for (int pile : piles) {
                hoursNeeded += (pile + mid - 1) / mid;
            }

            if (hoursNeeded > h)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};