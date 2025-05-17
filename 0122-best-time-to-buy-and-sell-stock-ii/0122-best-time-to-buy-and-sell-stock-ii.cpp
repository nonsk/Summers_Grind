class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, INT_MIN));
        dp[prices.size() - 1][1] = 0;
        dp[prices.size() - 1][0] = prices[prices.size() - 1];
        for (int index = prices.size() - 2; index >= 0; index--) {
            dp[index][1] =
                max(dp[index + 1][0] - prices[index], dp[index + 1][1]);
            dp[index][0] =
                max(dp[index + 1][1] + prices[index], dp[index + 1][0]);
        }
        return dp[0][1];
    }
};