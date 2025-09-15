class Solution {
public:
    map<pair<int,int>, int> mp;
    
    int recur(int index, int targetRem, vector<int>& nums) {
        if (index == -1) {
            return targetRem == 0 ? 0 : INT_MIN;
        }
        
        if (mp.find({index, targetRem}) != mp.end()) {
            return mp[{index, targetRem}];
        }
        int newTargetRem = (targetRem - nums[index] % 3 + 3) % 3;
        int include = nums[index] + recur(index - 1, newTargetRem, nums);
        int exclude = recur(index - 1, targetRem, nums);
        
        return mp[{index, targetRem}] = max(include, exclude);
    }
    
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        return recur(n - 1, 0, nums);
    }
};