class Solution {
public:
    int helper(int T, int index, int target, vector<int>& coins,
               vector<vector<int>>& dp) {
        if (T == target) {
            return 1;
        }
        if (T > target) {
            return 0;
        }
        if (index >= coins.size()) {
            return 0;
        }
        if (dp[index][T] != -1) {
            return dp[index][T];
        }
        dp[index][T] = helper(T + coins[index], index, target, coins, dp) +
                       helper(T, index + 1, target, coins, dp);
        return dp[index][T];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        return helper(0, 0, amount, coins, dp);
    }
};