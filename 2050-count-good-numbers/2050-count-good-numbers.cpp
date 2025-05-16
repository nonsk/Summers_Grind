class Solution {
public:
    int countGoodNumbers(long long n) {
        cout<<n<<endl;
        // 2,4,6,8,0
        // 2,3,5,7
        if (n == 1) {
            return 5;
        }
        if(n%4==0){
            long tempp = countGoodNumbers(n/2);
            // cout<<n<<","<<tempp*tempp;
            return tempp*tempp%(1000000007);
        }
        else if (n % 2 == 1) {
            // cout<<n<<","<<(long) 5 * countGoodNumbers(n - 1)%(1000000007);
            return (long) 5 * countGoodNumbers(n - 1)%(1000000007);
        } else {
            // cout<<n<<","<<(long) 4 * countGoodNumbers(n - 1)%(1000000007);
            return (long) 4 * countGoodNumbers(n - 1)%(1000000007);
        }
    }
};