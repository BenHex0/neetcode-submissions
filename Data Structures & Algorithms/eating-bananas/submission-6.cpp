class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());

        int k = piles[n - 1];
        int r = piles[n - 1];
        int l = 0;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int time = 0;
            int eats = m + 1;
            for (int j = 0; j < n; j++) {
                time += ceil((double)piles[j] / eats);
            }
            if (time > h)
                l = m + 1;
            else
                r = m - 1;
            if (time <= h) k = min(k, eats);
        }

        return k;
    }
};