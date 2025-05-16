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

        // Use a set directly to remove duplicates
        set<vector<int>> uniqueSubsets;
        for (auto& subset : ans) {
            uniqueSubsets.insert(subset); // No need to sort again; input was sorted
        }

        // Transfer back to vector
        return vector<vector<int>>(uniqueSubsets.begin(), uniqueSubsets.end());
    }
};
