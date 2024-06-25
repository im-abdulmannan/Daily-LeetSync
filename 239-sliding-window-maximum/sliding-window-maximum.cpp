class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<pair<int, int>> dq;

        for(int i = 0; i < nums.size(); i++) {
            if(!dq.empty() && dq.front().second <= (i - k))
            {
                dq.pop_front();
            }

            while(!dq.empty() && dq.back().first < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(make_pair(nums[i], i));

            if(i >= k - 1) {
                result.push_back(dq.front().first);
            }
        }

        return result;
    }
};