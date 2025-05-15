class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int back = 0;
        for (int front = 1; front < nums.size(); front++) {
            if (nums[front] != nums[back]) {
                back++;
                nums[back] = nums[front];
            }
        }
        return back + 1;
    }
};
