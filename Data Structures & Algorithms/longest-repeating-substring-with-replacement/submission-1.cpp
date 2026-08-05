class Solution {
   public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int l = 0;
        unordered_map<int, int> count;
        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            int windowLength = r - l + 1;
            int maxCount = 0;
            for (char i = 'A'; i <= 'Z'; i++) {
                maxCount = max(maxCount, count[i]);
            }

            if (windowLength - maxCount <= k) {
                res = max(res, windowLength);
            } else {
                while ((windowLength - maxCount) > k) {
                    count[s[l]]--;
                    l++;
                    windowLength = r - l + 1;
                }
            }
        }

        return res;
    }
};
