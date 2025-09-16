class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void recur(int index, vector<int>& temp, vector<int>& nums) {
        if (index == n) {
            ans.push_back(temp);
            return;
        }
        recur(index + 1, temp, nums);
        temp.push_back(nums[index]);
        recur(index + 1, temp, nums);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        recur(0, temp, nums);
        return ans;
    }
};