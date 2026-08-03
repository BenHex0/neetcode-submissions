class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> check(nums.begin(), nums.end());

        int longest = 0;
        for (int n : nums) {
            if (!check.count(n - 1)) {
                int length = 0;
                while (check.count(n)) {
                    length++;
                    n++;
                }
                longest = max(length, longest);
            }
        }

        return longest;
    }
};
