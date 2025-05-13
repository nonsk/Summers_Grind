class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 0);
        dp[0] = 1;
        for(int i =0; i<nums.size(); i++ ){
            if(dp[i]==0){
                continue;
            }
            for(int j =0; j<=nums[i]; j++){
                if(i+j>=dp.size()){
                    break;
                }
                dp[i+j] = 1;

            }
        }
        return (dp[nums.size()-1])?true:false;

    }
};