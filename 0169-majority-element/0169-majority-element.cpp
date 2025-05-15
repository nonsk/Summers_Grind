class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = INT_MIN;
        for(auto it : nums){
            if(mp.find(it)!=mp.end()){
                mp[it] += 1;
            }
            else{
                mp[it] = 1;
            }
        }
        int max_freq = 0;
        for(auto it : mp){
            if(it.second>max_freq){
                max_freq = it.second;
                ans = it.first;
            }
        }
        return (ans==INT_MIN)?nums[0]:ans;
    }
};