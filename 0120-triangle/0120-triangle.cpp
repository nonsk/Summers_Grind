class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& triangle,
               vector<vector<int>>& dp) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i == triangle.size() - 1) {
            dp[i][j] = triangle[i][j];
            return triangle[i][j];
        }
        dp[i][j] = min(helper(i + 1, j, triangle, dp),
                       helper(i + 1, j + 1, triangle, dp)) +
                   triangle[i][j];
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),
                               vector<int>(triangle.size(), -1));
        int ans = helper(0, 0, triangle, dp);
        return ans;
    }
};