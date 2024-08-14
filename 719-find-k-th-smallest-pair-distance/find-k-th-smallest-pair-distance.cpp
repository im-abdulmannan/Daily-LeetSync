class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minDistance = 0, maxDistance = nums.back() - nums.front();

        while(minDistance < maxDistance) {
            int midDistance = minDistance + (maxDistance - minDistance) / 2;
            if(countPairs(nums, midDistance) < k) {
                minDistance = midDistance + 1;
            } else {
                maxDistance = midDistance;
            }
        }

        return minDistance;
    }

    int countPairs(const vector<int>& nums, int target) {
        int cnt = 0, left = 0;
        for(int right = 1; right < nums.size(); right++) {
            while(nums[right] - nums[left] > target) {
                left += 1;
            }
            cnt += right - left;
        }

        return cnt;
    }
};