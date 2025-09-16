class Solution {
public:
    vector<int> dp;
    int n;
    int recur(int index, vector<int>& cost) {
        if (index == n)
            return 0;
        if (index > n)
            return 1e9;
        if(dp[index]!=-1)return dp[index];
        dp[index] =  min(recur(index + 1, cost), recur(index + 2, cost)) +
               cost[index];
               return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.assign(n+1,-1);
        return min(recur(0,cost), recur(1,cost));
    }
};