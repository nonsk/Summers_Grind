class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int x = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (k == j) {
                        continue;
                    }
                    if (dp[i + 1][k] < x) {
                        x = dp[i + 1][k];
                    }
                }
                dp[i][j] = x + grid[i][j];
                
            }
        }
        for (auto it : dp) {
            for (auto it2 : it) {
                cout << it2 << " ";
            }
            cout << endl;
        }
        int ans = INT_MAX;
        for (auto it : dp[0]) {
            if (it < ans) {
                ans = it;
            }
        }
        return ans;
    }
};