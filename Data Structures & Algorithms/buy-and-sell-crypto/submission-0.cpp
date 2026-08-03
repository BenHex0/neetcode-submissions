class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int profit = 0;
        for (int r = 1; r < prices.size(); r++) {
            int sell = prices[r] - prices[l];
            if (prices[r] < prices[l]) {
                r--;
                l++;
            }

            profit = max(sell, profit);
        }

        return profit;
    }
};
