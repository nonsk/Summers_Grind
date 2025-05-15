class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void sortColors(vector<int>& nums) {
        int z = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    swap(nums, i, z);
                    z++;
                }
            }
                        for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 1) {
                    swap(nums, i, z);
                    z++;
                }
            }
                        for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 2) {
                    swap(nums, i, z);
                    z++;
                }
            }
    }
};