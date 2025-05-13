class Solution {
public:
    int helper(int i, int j_1, int j_2, vector<vector<int>>& grid,
               vector<vector<vector<int>>>& dp) {
        int add;
        if (i >= grid.size())
            return 0;
        if (j_1 < 0 || j_2 < 0 || j_1 >= grid[0].size() ||
            j_2 >= grid[0].size())
            return 0;
        if (dp[i][j_1][j_2] != -1) {
            return dp[i][j_1][j_2];
        }
        if (j_1 == j_2) {
            add = grid[i][j_1];
        } else {
            add = grid[i][j_1] + grid[i][j_2];
        }
        dp[i][j_1][j_2] = max({
                              helper(i + 1, j_1 - 1, j_2 - 1, grid, dp),
                              helper(i + 1, j_1 - 1, j_2, grid, dp),
                              helper(i + 1, j_1 - 1, j_2 + 1, grid, dp),
                              helper(i + 1, j_1, j_2 - 1, grid, dp),
                              helper(i + 1, j_1, j_2, grid, dp),
                              helper(i + 1, j_1, j_2 + 1, grid, dp),
                              helper(i + 1, j_1 + 1, j_2 - 1, grid, dp),
                              helper(i + 1, j_1 + 1, j_2, grid, dp),
                              helper(i + 1, j_1 + 1, j_2 + 1, grid, dp),
                          }) +
                          add;
        return dp[i][j_1][j_2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(
            grid.size() + 1,
            vector<vector<int>>(grid[0].size() + 1,
                                vector<int>(grid[0].size() + 1, -1)));
        return helper(0, 0, grid[0].size() - 1, grid, dp);
    }
};