class Solution {
public:
    long long n;
    long long m;
    int numDistinct(string s, string t) {
        n = t.size();
        m = s.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0)); // Changed: unsigned long long

        unsigned long long temp = 0; // Changed: unsigned long long
        if(s[0]==t[0])dp[0][0] = 1;
        for (long long j = 1; j < m; j++) {
            if (t[0] == s[j]) {
                dp[0][j] = 1 + dp[0][j-1];
            }
            else {
                dp[0][j] = dp[0][j-1];
            }
        }
        for (long long i = 1; i < n; i++) {
            long long curr = 0;
            for (long long j = 1; j < m; j++) {
                dp[i][j] = dp[i][j-1];
                if (t[i] == s[j]) {
                    dp[i][j] += dp[i - 1][j-1];
                }
            }
        }
        return (int)dp[n-1][m-1]; // Changed: explicit cast to int
    }
};