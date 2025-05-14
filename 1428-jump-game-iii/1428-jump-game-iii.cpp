class Solution {
public:
    bool helper(int i, vector<int>& arr, vector<int>& visiting) {
        if (i >= arr.size() || i < 0 || visiting[i]) {
            return false;
        }
        if (arr[i] == 0) {
            return true;
        }
        visiting[i] = 1;
        int ans = helper(i + arr[i], arr, visiting) ||
                  helper(i - arr[i], arr, visiting);
        return ans;
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> visiting(arr.size()+1,0);
        return helper(start, arr, visiting);
    }
};