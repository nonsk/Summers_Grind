class Solution {
public:
    bool helper(int index, vector<int>& nums, unordered_map<int, bool>& mp) {
        if (mp.find(index) != mp.end()) {
            return mp[index];
        }
        if (index == nums.size() - 1) {
            mp[index] = true;
            return mp[index];
        } else if (index >= nums.size()) {
            mp[index] = false;
            return mp[index];
        } else if (nums[index] == 0) {
            mp[index] = false;
            return mp[index];
        } else {
            for (int i = 1; i <= nums[index]; i++) {
                if (helper(index + i, nums, mp)) {
                    mp[index] = true;
                    return mp[index];
                }
            }
        }
        mp[index] = false;
        return mp[index];
    }
    bool canJump(vector<int>& nums) {
        // unordered_map<int, bool> mp;
        // return helper(0, nums, mp);
        vector<int> dp(nums.size()+1, 0);
        dp[0] = 1;
        for(int i =0; i<nums.size(); i++ ){
            if(dp[i]==0){
                continue;
            }
            for(int j =0; j<=nums[i]; j++){
                if(i+j>=dp.size()){
                    continue;
                }
                dp[i+j] = 1;

            }
        }
        return (dp[nums.size()-1])?true:false;

    }
};