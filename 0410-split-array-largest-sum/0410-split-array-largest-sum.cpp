class Solution {
public:
    bool can(int mid, vector<int>& nums, int k) {
        int rem = mid;
        int labor = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mid) {
                return false;
            }
            if (nums[i] <= rem) {
                rem -= nums[i];
            } else {
                rem = mid - nums[i];
                labor++;
                if (labor > k) {
                    return false;
                }
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {

        int tot = 0;
        int maxElement = 0;
        for (auto it : nums) {
            tot += it;
            maxElement = max(maxElement, it);
        }
        int lo = maxElement;
        int hi = tot;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(mid, nums, k)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};