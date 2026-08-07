class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> count1;
        for (char c : s1) {
            count1[c]++;
        }

        int check = count1.size();
        int length = s2.length() - s1.length() + 1;
        ;

        for (int i = 0; i < length; i++) {
            unordered_map<char, int> count2;
            int cur = 0;
            for (int j = i; j < (i + s1.length()); j++) {
                char c = s2[j];
                count2[c]++;

                if (count1[c] == count2[c]) {
                    cur++;
                }

                if (cur == check) {
                    return true;
                }
            }
        }
        return false;
    }
};