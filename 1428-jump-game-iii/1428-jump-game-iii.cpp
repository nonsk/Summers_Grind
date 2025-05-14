class Solution {
public:
    bool helper(int i, vector<int>& arr, unordered_set<int>& visiting) {
        if (visiting.count(i) > 0) {
            return false;
        }
        if (i >= arr.size() || i < 0) {
            return false;
        }
        if(arr[i]==0){
            return true;
        }
        visiting.insert(i);
        int ans = helper(i + arr[i], arr, visiting) ||
                  helper(i - arr[i], arr, visiting);
        // visiting.erase(i); 
        return ans;
    }

    bool canReach(vector<int>& arr, int start) {
        unordered_map<int, bool> dp;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                dp[i] = true;
            }
        }
        unordered_set<int> visiting;
        return helper(start, arr, visiting);
    }
};