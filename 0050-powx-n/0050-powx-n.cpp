class Solution {
public:
    double myPow(double x, long n) {
        if (n == 1) {
            return x;
        }
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return myPow(1 / x, (-1) * n);
        }
        return (n%2==1)?x*myPow(x*x,(n-1)/2):x*x*myPow(x*x,(n-1)/2);
    }
};