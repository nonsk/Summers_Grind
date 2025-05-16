class Solution {
public:
    void f(int i, vector<int> &temp, int k, int n, vector<vector<int>> &ans) {
        if (n == 0 && k == 0) {
            ans.push_back(temp);
            return;
        }
        if (i > 9 || n < 0 || k < 0) return;

        // take
        temp.push_back(i);
        f(i + 1, temp, k - 1, n - i, ans);
        temp.pop_back();

        // not take
        f(i + 1, temp, k, n, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(1, temp, k, n, ans);
        return ans;
    }
};
