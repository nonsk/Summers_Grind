class Solution {
public:
    int helper(int i, int sum, vector<int>& nums, vector<int>& dp) {
        if (i < 0) {
            return sum;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if (i == nums.size()) {
            dp[i] =
                sum + max(helper(i - 1, sum, nums,dp), helper(i - 2, sum, nums,dp));
        } else {
            dp[i] = sum + max(helper(i - 1, sum, nums,dp),
                              helper(i - 2, sum, nums,dp) + nums[i]);
        }
        return dp[i];
    }
    int rob(vector<int>& nums) { 
        vector<int> dp(nums.size()+1, -1);
        return helper(nums.size(), 0, nums,dp); }
};