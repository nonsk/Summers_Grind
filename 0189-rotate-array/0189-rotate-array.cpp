class Solution {
public:
    void helper(vector<int>& nums, int start, int end){
        while(start<=end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        helper(nums,0, nums.size()-k-1);
        helper(nums,nums.size()-k, nums.size()-1);
        helper(nums,0, nums.size()-1);
    }
};