class Solution {
   public:
    bool isPalindrome(string s) {
        int r = 0, l = s.length() - 1;

         while (r < l) {
            if (!isalnum(s[l])) {
                l--;
                continue;
            }

            if (!isalnum(s[r])) {
                r++;
                continue;
            }

            if (tolower(s[l]) != tolower(s[r])) return false;

            r++;
            l--;
        }

        return true;
    }
};
