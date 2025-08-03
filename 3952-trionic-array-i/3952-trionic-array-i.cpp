class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int n = nums.size();
        int c = 0;
        int p = -1;
        int q = -1;
        for (int i = 1; i < n; i++) {
            if(nums[i]==nums[i-1]){
                return false;
            }
            if (c == 0) {
                if (nums[i] <= nums[i - 1]) {
                    p = i - 1;
                    c = 1;
                    continue;
                }
            } else if (c == 1) {
                if (nums[i] >= nums[i - 1]) {
                    q = i - 1;
                    c = 2;
                    continue;
                }
            }
            else if(c==2){
                if(nums[i]<=nums[i-1]){
                    return false;
                }
            }
        }
        if(nums[n-1]<=nums[n-2]){
            return false;
        }
        cout<<p<<endl<<q;
        if (c != 2 || p <= 0 || q <= 0 || p >= q || p >= n - 1 || q >= n - 1) {
            return false;
        }

        return true;
    }
};