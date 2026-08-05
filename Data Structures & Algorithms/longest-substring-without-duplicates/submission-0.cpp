class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> check;
        int longest = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            while (check.count(s[r])) {
                check.erase(s[l]);
                l++;
            }

            check.insert(s[r]);

            int length = (r - l) + 1;

            if (longest < length) {
                longest = length;
            }
        }

        return longest;
    }
};
