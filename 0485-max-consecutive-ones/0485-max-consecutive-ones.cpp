class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int yo = INT_MIN; 
        for(auto it : nums){
            if(it==1){
                ans +=1;
            }
            else{
                ans = 0;
            }
            yo = max(yo, ans);
        }
        return yo;
    }
};