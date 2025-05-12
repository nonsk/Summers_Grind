class Solution {
public:
    int fib(int n) {
        if(n<=1){
            return n;
        }
        int curr;
        int prev=0;
        int prev2=1;
        for (int i = 0; i < n; i++) {
            curr = prev+prev2;
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};