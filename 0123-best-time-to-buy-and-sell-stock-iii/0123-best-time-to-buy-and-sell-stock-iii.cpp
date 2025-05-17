class Solution {
public:
    int recur(bool can, vector<int>& prices, int index, vector<vector<vector<int>>> &dp, int l) {

        if(dp[index][can][l]!=INT_MIN){
            return dp[index][can][l];
        }
        if(l<=0){
            return 0;
         }
        if (index == prices.size() - 1) {
            if (can) {
                dp[index][1][l] = 0;
                return 0;
            } else {
                dp[index][0][l] = prices[index];
                return prices[index];
            }
        }
        dp[index][1][l] = max(recur(false, prices, index + 1,dp, l) - prices[index],
                       recur(true, prices, index + 1,dp, l));
        dp[index][0][l] = max(recur(true, prices, index + 1,dp, l-1) + prices[index],
                       recur(false, prices, index + 1,dp, l));
        if (can) {
            return dp[index][1][l];
        } else {
            return dp[index][0][l];
        }
    }
    int maxProfit(vector<int>& prices) {
        int l =2;
        vector<vector<vector<int>>> dp (prices.size()+1,vector<vector<int>>(2,vector<int>(l+1,INT_MIN)));
        return recur(true, prices, 0, dp, l);
    }
};