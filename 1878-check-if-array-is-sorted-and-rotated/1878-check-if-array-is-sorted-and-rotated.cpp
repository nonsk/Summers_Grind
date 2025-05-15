class Solution {
public:
    bool check_sort(vector<int>& nums, int start, int end) {
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }

    bool check(vector<int>& nums) {
        int dis = -1;
        int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                if (dis != -1) return false; // more than one drop
                dis = i;
            }
        }

        if (dis == -1) return true; // already sorted

        // check two sorted parts and the boundary wraparound
        return check_sort(nums, 0, dis - 1) && 
               check_sort(nums, dis, n - 1) &&
               nums[n - 1] <= nums[0];
    }
};
