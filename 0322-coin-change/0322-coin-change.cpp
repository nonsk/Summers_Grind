class Solution {
public:
    int helper(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (index < 0 || amount < 0) return 1e9;
        if (dp[index][amount] != -1) return dp[index][amount];
        
        int not_take = helper(index - 1, amount, coins, dp);
        int take = 1e9;
        if (amount >= coins[index]) {
            take = 1 + helper(index, amount - coins[index], coins, dp);
        }
        dp[index][amount] = min(not_take, take);
        return dp[index][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(n - 1, amount, coins, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};
