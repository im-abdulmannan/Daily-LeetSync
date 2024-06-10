class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxArea = 0;

        while(l < r) {
            int area = min(height[l], height[r]) * (r - l);
            maxArea = max(maxArea, area);

            if(height[l]<height[r])
                l++;
            else
                r--;
        }

        return maxArea;
    }
};