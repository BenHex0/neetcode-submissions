class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> people;

        for (int i = 0; i < trust.size(); i++) people[trust[i][1]]++;

        unordered_map<int, bool> people2;

        for (int i = 0; i < trust.size(); i++) people2[trust[i][0]] = true;

        for (int i = 1; i <= n; i++)
            if (people[i] == n - 1 && people2[i] == false) {
                return i;
            }

        return -1;
    }
};