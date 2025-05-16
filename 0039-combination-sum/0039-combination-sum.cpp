class Solution {
public:
    void recur(vector<int>& candidates, int index, vector<int>& temp,
               vector<vector<int>>& ans, int target, int sum) {

        if (sum > target) {
            return;
        }
        if (index >= candidates.size()) {
            if (index == candidates.size() && sum == target) {
                ans.push_back(temp);
            }
            return;
        }
        // not take
        recur(candidates, index + 1, temp, ans, target, sum);
        // take
        temp.push_back(candidates[index]);
        recur(candidates, index, temp, ans, target, sum + candidates[index]);

        // pop
        sum -= candidates[index];
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        recur(candidates, 0, temp, ans, target, 0);
        return ans;
    }
};