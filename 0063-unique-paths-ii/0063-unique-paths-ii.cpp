class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        long m = obstacleGrid.size();
        long n = obstacleGrid[0].size();
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = 1;
                }
            }
        }
        return dp[0][0];
    }
};