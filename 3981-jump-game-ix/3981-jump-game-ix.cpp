class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_num_so_far(n), shortest_ahead(n), ans(n);
        max_num_so_far[0] = nums[0];
        shortest_ahead[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            max_num_so_far[i] = max(max_num_so_far[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            shortest_ahead[i] = min(shortest_ahead[i + 1], nums[i]);
        }

        ans[n - 1] = max_num_so_far[n - 1]; 
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = max_num_so_far[i];
            // If left_max > right_min, we can jump to left and ride to right part
            // And as the right values are greater or equal we prefer those
            if (ans[i] > shortest_ahead[i + 1]) {
                ans[i] = ans[i + 1];
            }
        }

        return ans;
    }
};