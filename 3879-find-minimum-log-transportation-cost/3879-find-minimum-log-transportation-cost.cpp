class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long cost = 0;
        for (int i = 0; i < 3; i++) {
            if (m > n) {
                if (m > k) {

                    m = m - k;
                    cost +=1LL * m * k;
                }

            } else {
                if (n > k) {

                    n = n - k;
                    cost +=1LL * n * k;
                }
            }
        }
        return cost;
    }
};