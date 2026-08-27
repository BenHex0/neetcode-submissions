class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int c = l + (r - l) / 2;

            if (nums[c] < target)
                l = c + 1;
            else if (nums[c] > target)
                r = c - 1;
            else
                return c;
        }

        return -1;
    }
};
