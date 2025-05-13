class Solution {
public:
    int helper(int i, int sum, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            if (sum == target / 2) {
                return 1;
            }
            return 0;
        }
        if (dp[i][sum] != -1) {
            return dp[i][sum];
        }
        int skip = helper(i + 1, sum, nums, target, dp);
        int take = helper(i + 1, sum + nums[i], nums, target, dp);
        dp[i][sum] = skip || take;
        return dp[i][sum];
    }
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int i = 0; i < nums.size(); i++) {
            target += nums[i];
        }
        if (target % 2 == 1) {
            return false;
        }
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target+1, -1));
        return helper(0, 0, nums, target, dp);
    }
};