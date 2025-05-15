class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = 0;
        for(auto it : nums){
            sum +=it;
        }
        return n*(n+1)/2 - sum;
    }
};