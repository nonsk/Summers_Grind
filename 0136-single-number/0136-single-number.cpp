class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        for(auto it : nums){
            if(s.find(it)!=s.end()){
                s.erase(it);
            }
            else{
                s.insert(it);
            }
        }
        for(auto it : s){
            return it;
        }
        return nums[0];
    }
};