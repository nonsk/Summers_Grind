class Solution {
public:
    int dfs(vector<int>& nums, int index, int sum, int target) {
        if (index == nums.size()) {
            return sum == target ? 1 : 0;
        }
        return dfs(nums, index + 1, sum + nums[index], target) +
               dfs(nums, index + 1, sum - nums[index], target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, 0, 0, target);
    }
};