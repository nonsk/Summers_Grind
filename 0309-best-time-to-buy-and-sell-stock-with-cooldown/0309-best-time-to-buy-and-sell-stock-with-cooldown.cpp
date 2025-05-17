class Solution {
public:
    int recur(bool can, vector<int>& prices, int index, vector<vector<int>> &dp) {
        if (index >= prices.size()) return 0;
        if (dp[index][can] != INT_MIN) {
            return dp[index][can];
        }
        dp[index][1] = max(recur(false, prices, index + 1, dp) - prices[index],
                           recur(true, prices, index + 1, dp));
        dp[index][0] = max(recur(true, prices, index + 2, dp) + prices[index],
                           recur(false, prices, index + 1, dp));
        return dp[index][can];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 2, vector<int>(2, INT_MIN));
        return recur(true, prices, 0, dp);
    }
};
