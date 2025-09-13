class Solution {
public:
    int tot = 0;
    int n;
    vector<vector<int>> dp;
    bool recur(int index, int sum, vector<int>& nums) {
        if (sum == tot / 2) {
            return true;
        }
        if (index == n) {
            return false;
        }
        if (dp[index][sum] != -1)
            return dp[index][sum];
        bool take = recur(index + 1, sum, nums);
        bool notTake = recur(index + 1, sum + nums[index], nums);
        dp[index][sum] = take || notTake;
        return dp[index][sum];
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i < n; i++) {
            tot += nums[i];
        }
        if (tot % 2 == 1)
            return false;
        dp.resize(nums.size(), vector<int>(tot, -1));
        return recur(0, 0, nums);
    }
};