class Solution {
public:
    void recur(vector<int>& nums, int index, vector<int> temp,
               set<vector<int>>& ans) {
        if (index == nums.size())
            {ans.insert(temp);
            return;
            }

        recur(nums, index + 1, temp, ans);
        temp.push_back(nums[index]);
        recur(nums, index + 1, temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> ans;
        recur(nums, 0, {}, ans);
        vector<vector<int>> new_ans;
        for (auto it : ans) {
            new_ans.push_back(it);
        }
        return new_ans;
    }
};