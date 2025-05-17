
class Solution {
public:
    int recur(bool can, vector<int>& prices, int index, vector<vector<int>>& dp,
              int fee) {
        if (index >= prices.size()) return 0;
        if (dp[index][can] != INT_MIN) {
            return dp[index][can];
        }
        dp[index][1] =
            max(recur(false, prices, index + 1, dp, fee) - prices[index],
                recur(true, prices, index + 1, dp, fee));
        dp[index][0] =
            max(recur(true, prices, index + 1, dp, fee) + prices[index] - fee,
                recur(false, prices, index + 1, dp, fee));
        if (can) {
            return dp[index][1];
        } else {
            return dp[index][0];
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, INT_MIN));
        return recur(true, prices, 0, dp, fee);
    }
};