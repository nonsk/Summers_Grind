class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1) {
                    dp[i][j] = matrix[i][j];
                    continue;
                }
                if (j == 0) {
                    dp[i][j] =
                        min(dp[i + 1][j], dp[i + 1][j + 1]) + matrix[i][j];
                        continue;
                }
                dp[i][j] =
                        min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]}) + matrix[i][j];
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