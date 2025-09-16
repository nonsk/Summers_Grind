class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // Add boundary balloons with value 1
        vector<int> arr(n + 2);
        arr[0] = 1;
        arr[n + 1] = 1;
        for (int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }
        
        // dp[i][j] = max coins by bursting all balloons between i and j (exclusive)
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        // len is the length of the interval
        for (int len = 2; len <= n + 1; len++) {
            for (int i = 0; i <= n + 1 - len; i++) {
                int j = i + len;
                // Try bursting each balloon k as the LAST one in interval (i, j)
                for (int k = i + 1; k < j; k++) {
                    // When k is the last balloon to burst in (i, j):
                    // - Left boundary is i, right boundary is j
                    // - Coins gained: arr[i] * arr[k] * arr[j]
                    // - Plus coins from left subproblem: dp[i][k]  
                    // - Plus coins from right subproblem: dp[k][j]
                    dp[i][j] = max(dp[i][j], 
                                   dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j]);
                }
            }
        }
        
        return dp[0][n + 1];
    }
};

// Alternative: Recursive solution with memoization
class Solution2 {
public:
    vector<vector<int>> memo;
    vector<int> arr;
    
    int solve(int left, int right) {
        if (left + 1 == right) return 0;  // No balloons between left and right
        
        if (memo[left][right] != -1) return memo[left][right];
        
        int maxCoins = 0;
        // Try bursting each balloon k as the LAST one between left and right
        for (int k = left + 1; k < right; k++) {
            int coins = solve(left, k) + solve(k, right) + arr[left] * arr[k] * arr[right];
            maxCoins = max(maxCoins, coins);
        }
        
        return memo[left][right] = maxCoins;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        arr.resize(n + 2);
        arr[0] = 1;
        arr[n + 1] = 1;
        for (int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }
        
        memo.assign(n + 2, vector<int>(n + 2, -1));
        return solve(0, n + 1);
    }
};