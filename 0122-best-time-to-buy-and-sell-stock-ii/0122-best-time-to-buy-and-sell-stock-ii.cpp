class Solution {
public:
    int recur(bool can, vector<int>& prices, int index, vector<vector<int>> &dp) {
        if(dp[index][can]!=INT_MIN){
            return dp[index][can];
        }
        if (index == prices.size() - 1) {
            if (can) {
                dp[index][1] = 0;
                return 0;
            } else {
                dp[index][0] = prices[index];
                return prices[index];
            }
        }
        dp[index][1] = max(recur(false, prices, index + 1,dp) - prices[index],
                       recur(true, prices, index + 1,dp));
        dp[index][0] = max(recur(true, prices, index + 1,dp) + prices[index],
                       recur(false, prices, index + 1,dp));
        if (can) {
            return dp[index][1];
        } else {
            return dp[index][0];
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp (prices.size()+1,vector<int>(2,INT_MIN));
        return recur(true, prices, 0, dp);
    }
};