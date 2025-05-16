class Solution {
public:
    void recur(vector<int>& nums,int index, vector<int> temp, set<vector<int>> &ans){
        ans.insert(temp);
        if(index>=nums.size()) return;
        recur(nums,index+1, temp, ans);
        temp.push_back(nums[index]);
        recur(nums,index+1, temp, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> ans;
        recur(nums,0,{},ans);
        vector<vector<int>> new_ans;
        for(auto it : ans){
            new_ans.push_back(it);
        }
        return new_ans;
    }
};