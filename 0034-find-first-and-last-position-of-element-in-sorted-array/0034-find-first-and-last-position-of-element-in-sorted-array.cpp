class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }
        int l = 0;
        int r = nums.size() - 1;
        int a1 = -1, a2 = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                a1 = mid;
                r = mid - 1;
            }
        }
        l = 0;
        r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
                a2 = mid;
            } else {
                r = mid - 1;
            }
        }
        if (a1 != -1 && a2 != -1 && nums[a1] == target && nums[a1] == target) {

            return {a1, a2};
        }
        return {-1, -1};
    }
};