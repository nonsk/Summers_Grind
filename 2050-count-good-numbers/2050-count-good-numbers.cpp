class Solution {
public:
    int mod = 1e9+7;
    
    long long pow1(long long base, long long exp) {
        long long ans = 1;
        while (exp) {
            if (exp % 2) { 
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return ans;
    }
     
    int countGoodNumbers(long long n) {
        long long even_place = (n + 1) / 2; 
        long long odd_place = n / 2;       
        
        long long even = pow1(5, even_place) % mod;
        long long odd = pow1(4, odd_place) % mod;
        
        return (even * odd) % mod;
    }
};