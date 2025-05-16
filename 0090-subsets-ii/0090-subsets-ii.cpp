class Solution {
public:
    void sub(vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds,int i){
        if(i == nums.size()){
            if(find(ans.begin(), ans.end(), ds) == ans.end()){
                ans.push_back(ds);
            }
            return;
        }
        ds.push_back(nums[i]);
        sub(nums, ans,ds,i+1);
        ds.pop_back();
        sub(nums,ans,ds,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        sub(nums,ans,ds,0);
        return ans;
    }
};