class Solution {
public:
    int helper(int i1, int i2, string& text1, string& text2,
               vector<vector<int>>& dp) {
        if (i1 == text1.size() || i2 == text2.size()) {
            return 0;
        }
        if (dp[i1][i2] != -1) {
            return dp[i1][i2];
        }
        if (text1[i1] == text2[i2]) {
            dp[i1][i2] = 1 + helper(i1 + 1, i2 + 1, text1, text2, dp);
        } else {
            dp[i1][i2] = max(helper(i1 + 1, i2, text1, text2, dp),
                             helper(i1, i2 + 1, text1, text2, dp));
        }
        return dp[i1][i2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return helper(0, 0, text1, text2, dp);
    }
};