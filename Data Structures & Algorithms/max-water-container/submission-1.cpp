class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int maxWater = 0;
        while (l < r)
        {
            int water = (r - l) * min(heights[r], heights[l]);
            maxWater = max(water, maxWater);
            (heights[l] < heights[r])? l++ : r--;
        }

        return maxWater;
    }
};
