class Solution {
public:
    bool helper(int i, vector<int>& arr, unordered_map<int, bool>& dp,
                unordered_set<int>& visiting) {
        if (visiting.count(i) > 0) {
            return false;
        }
        if (dp.find(i) != dp.end()) {
            return dp[i];
        }
        if (i >= arr.size() || i < 0) {
            return false;
        }
        visiting.insert(i);
        dp[i] = helper(i + arr[i], arr, dp, visiting) ||
                helper(i - arr[i], arr, dp, visiting);
        visiting.erase(i);//very very important
        return dp[i];
    }

    bool canReach(vector<int>& arr, int start) {
        unordered_map<int, bool> dp;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                dp[i] = true;
            }
        }
        unordered_set<int> visiting;
        return helper(start, arr, dp, visiting);
    }
};