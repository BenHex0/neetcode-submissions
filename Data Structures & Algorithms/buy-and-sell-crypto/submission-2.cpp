class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int profit = 0;
        for (int r = 1; r < prices.size(); r++) {
            if (prices[l] < prices[r]) {
                int sell = prices[r] - prices[l];
                profit = max(profit, sell);
            } else {
             
                l = r;
            }
        }

        return profit;
    }
};
