class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid = (l+r)/2;
        while(l<=r){
            // cout<<l<<","<<r<<endl;
            if(target==nums[mid]){
                return mid;
            }
            if(target<nums[mid]){
                r = mid-1;
            }
            if(target>nums[mid]){
                l = mid+1;
            }
                mid = (l+r)/2;
        }
        return -1;
    }
};