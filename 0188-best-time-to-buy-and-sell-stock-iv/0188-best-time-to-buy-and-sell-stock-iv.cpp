class Solution {
public:
    int maxProfit(int k,vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int index = prices.size() - 1; index >= 0; index--) {
            for (int cap = 1; cap <= k; cap++) {
                dp[index][1][cap] = max(dp[index + 1][0][cap] - prices[index], dp[index + 1][1][cap]);
                dp[index][0][cap] = max(dp[index + 1][1][cap - 1] + prices[index], dp[index + 1][0][cap]);
            }
        }
        return dp[0][1][k];
    }
};
