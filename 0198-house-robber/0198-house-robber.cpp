class Solution {
public:
    int n;
    vector<int> dp;
    int recur(int index, vector<int>& nums) {
        if (index >= n)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        dp[index] =
            max(recur(index + 1, nums), recur(index + 2, nums) + nums[index]);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        dp.assign(n + 1, -1);
        return recur(0, nums);
    }
};