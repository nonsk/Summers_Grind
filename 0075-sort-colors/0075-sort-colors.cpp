class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void sortColors(vector<int>& nums) {
        int z = 0;
        for (int n = 0; n < 3; n++) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == n) {
                    swap(nums, i, z);
                    z++;
                }
            }
        }
    }
};