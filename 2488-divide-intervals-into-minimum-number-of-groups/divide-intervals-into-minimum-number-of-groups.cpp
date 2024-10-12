class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        vector<int> start_times, end_times;

        for(const auto& interval : intervals) {
            start_times.push_back(interval[0]);
            end_times.push_back(interval[1]);
        }

        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int end_ptr = 0, grp_cnt = 0;

        for(int s : start_times) {
            if(s > end_times[end_ptr]) {
                end_ptr++;
            } else {
                grp_cnt++;
            }
        }

        return grp_cnt;
    }
};