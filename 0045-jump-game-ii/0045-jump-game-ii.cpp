class Solution {
public:
    int helper(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size()-1) {
            return 0;
        }
        if (dp[i] != INT_MAX) {
            return dp[i];
        }
        for (int j = 1; j <= nums[i]; j++) {
            if (i + j < nums.size()) {
                int subproblem = helper(i + j, nums, dp);
                if (subproblem != INT_MAX) {
                    dp[i] = min(dp[i], 1 + subproblem);
                }
            }
        }
        return dp[i];
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, INT_MAX);
        return helper(0, nums, dp);
    }
};