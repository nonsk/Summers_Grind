class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = nums[0];
        int max_freq = 0;
        for(auto it : nums){
            if(mp.find(it)==mp.end()){
                mp[it] = 1;
            }
            else{
                mp[it] += 1;
            }
            if(mp[it]>max_freq){
                max_freq = mp[it];
                ans = it;
            }
        }
        return ans;
    }
};