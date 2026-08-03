class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int res = 0, maxCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
            res = (count[nums[i]] > maxCount)? nums[i] : res;
            maxCount = max(maxCount, count[nums[i]]);
        }

        return res;
    }
};