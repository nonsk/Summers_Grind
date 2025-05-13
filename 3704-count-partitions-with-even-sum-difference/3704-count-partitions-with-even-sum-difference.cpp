class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum_r = 0;
        int sum_l = nums[0];
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            sum_r += nums[i];
        }
        for (int i = 1; i < nums.size(); i++) {
            sum_l += nums[i];
            sum_r -= nums[i];
            if ((sum_l - sum_r) % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};