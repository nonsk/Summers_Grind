class Solution {
public:
    int helper(vector<int>& cost, int n, vector<int>& dp) {
        if (n < 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        if (n == cost.size()) {
            dp[n] = min(helper(cost, n - 1, dp), helper(cost, n - 2, dp));
        } else {
            dp[n] =
                min(helper(cost, n - 1, dp), helper(cost, n - 2, dp)) + cost[n];
        }
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i =2; i<n; i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
            
        }
        for(auto it : dp){
            cout<<it<<" ";
        }
        return min(dp[n-2],dp[n-1]);
    }
};