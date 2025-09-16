class Solution {
public:
    vector<int> dp;
    int n;
    int recur(int index, vector<int>& nums) {
        if (index == -1)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int ans = 1;
        for (int i = index - 1; i >= 0; i--) {
            if (nums[i] < nums[index]) {
                ans = max(ans, 1 + recur(i, nums));
            }
        }
        dp[index] = ans;
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.assign(n + 1, -1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, recur(i, nums));
        }
        return ans;
    }
};