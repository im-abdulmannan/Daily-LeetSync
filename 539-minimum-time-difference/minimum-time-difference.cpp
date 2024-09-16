class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n = timePoints.size();
        if(n > 1440) return 0;
        vector<int> minutes(n);

        for(int i = 0; i < n; i++) {
            int hour = stoi(timePoints[i].substr(0, 2));
            int min = stoi(timePoints[i].substr(3, 2));
            minutes[i] = hour * 60 + min;
        }

        sort(minutes.begin(), minutes.end());
        int minDiff = 1440;
        for(int i = 0; i < n - 1; i++) {
            minDiff = min(minDiff, minutes[(i + 1) % n] - minutes[i]);
        }

        minDiff = min(minDiff, 1440 + minutes[0] - minutes[n - 1]);

        return minDiff;
    }
};