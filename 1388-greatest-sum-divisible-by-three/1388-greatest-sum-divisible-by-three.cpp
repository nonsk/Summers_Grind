class Solution {
public:
    vector<vector<int>> dp;
    int recur(int index, int rem,vector<int>& nums){
        if(index==nums.size()){
            if(rem == 0){
                return 0;
            }
            else{
                return (1e9+7)*(-1);
            }
        }
        if(dp[index][rem]!=-1)return dp[index][rem];
        // take
        int take = recur(index+1, ((nums[index]+rem)%3+3)%3,nums) + nums[index];
        int notake = recur(index+1,rem,nums);
        dp[index][rem] = max(take, notake);
        return dp[index][rem];
    }
    int maxSumDivThree(vector<int>& nums) {
        dp.assign(nums.size()+1, vector<int>(3,-1));
        return recur(0,0, nums);
    }
};