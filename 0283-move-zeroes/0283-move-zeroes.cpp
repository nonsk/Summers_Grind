class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int back = 0;
        for (int front = 0; front < nums.size(); front++) {
            if (nums[front] != 0) {
                swap(nums[back],nums[front]);
                back++;
            }
        }
        return;
    }
};