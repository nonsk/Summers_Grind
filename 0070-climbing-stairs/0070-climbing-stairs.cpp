class Solution {
public:
    int climbStairs(int n) {
       if(n<=2){
            return n;
        }
        int curr;
        int prev=2;
        int prev2=1;
        for (int i = 0; i < n-2; i++) {
            curr = prev+prev2;
            prev2 = prev;
            prev = curr;
            // cout << prev2 <<" "<<prev<<" "<<curr<<" \n";
        }

        return curr;
    }
};