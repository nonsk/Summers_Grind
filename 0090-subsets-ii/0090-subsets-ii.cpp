class Solution {
public:
    void recur(const vector<int>& nums, int index, vector<int>& temp,
               vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }
        recur(nums, index + 1, temp, ans); // Exclude
        temp.push_back(nums[index]);       // Include
        recur(nums, index + 1, temp, ans);
        temp.pop_back();                   // Backtrack
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        recur(nums, 0, temp, ans);

        // Remove duplicates using set
        set<vector<int>> unique(ans.begin(), ans.end());

        // Convert back to vector
        return vector<vector<int>>(unique.begin(), unique.end());
    }
};
