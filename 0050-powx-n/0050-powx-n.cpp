class Solution {
public:
    double myPow(double x, int n) {
        cout << x << " and " << n << endl;
        if (n == 0) {
            return 1;
        }
        if(n<0){
            return (1/myPow(x,-n));
        }
        if(n==1){
            return x;
        }
        if(n%2==1){
            return x*myPow(x*x, (n-1)/2);
        }
        return x*x*myPow(x*x,(n-1)/2);
    }
};