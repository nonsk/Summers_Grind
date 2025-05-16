class Solution {
public:
    int countGoodNumbers(long long n) {
        if (n == 1) {
            return 5;
        }
        if (n == 2) {
            return 20;
        }
        if(n%4==0){
            long temp = countGoodNumbers(n/2);
            return temp*temp% (1000000007);
        }
        if (n % 2 == 1) {

            return (long)5 * countGoodNumbers(n - 1) % (1000000007);
        } else {

            return (long)4 * countGoodNumbers(n - 1) % (1000000007);
        }
    }
};