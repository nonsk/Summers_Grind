class Solution {
public:
    void recur(vector<int>& nums, int index, vector<int>& temp,
               vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }
        recur(nums, index + 1, temp, ans);
        temp.push_back(nums[index]);
        recur(nums, index + 1, temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        recur(nums, 0, temp, ans);
        set<vector<int>>tempp;
        for(auto it : ans){
            sort(it.begin(), it.end());
        }
        for(auto it : ans){
            tempp.insert(it);
        }
        ans = {};
        for(auto it : tempp){
            ans.push_back(it);
        }
        return ans;
    }
};