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
        unordered_map<int, bool> mp;
        return helper(0, nums, mp);
    }
};