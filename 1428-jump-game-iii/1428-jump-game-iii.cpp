class Solution {
private:
    bool helper(int i, vector<int>& arr, vector<int>& visiting) {
        if ( i < 0 ||i >= arr.size()||visiting[i]) {
            return false;
        }
        if (arr[i] == 0) {
            return true;
        }
        visiting[i] = 1;
        return helper(i + arr[i], arr, visiting) ||
               helper(i - arr[i], arr, visiting);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> visiting(arr.size(), 0);
        return helper(start, arr, visiting);
    }
};