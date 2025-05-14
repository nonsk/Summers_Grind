class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int jumps = 0;
        int currentMax = 0;  // The furthest position that can be reached
        int nextMax = 0;     // The furthest position that can be reached after one more jump
        
        // We don't need to check the last element
        for (int i = 0; i < n - 1; i++) {
            // Update the furthest position we can reach
            nextMax = max(nextMax, i + nums[i]);
            
            // If we've reached the boundary of our current jump
            if (i == currentMax) {
                // Take another jump
                jumps++;
                currentMax = nextMax;
                
                // If we can already reach the end, no need to continue
                if (currentMax >= n - 1) break;
            }
        }
        
        return jumps;
    }
};