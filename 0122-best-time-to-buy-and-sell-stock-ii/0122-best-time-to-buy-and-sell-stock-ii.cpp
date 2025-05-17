class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, INT_MIN));
        int one = 0;
        int zero = prices[prices.size() - 1];
        for (int index = prices.size() - 2; index >= 0; index--) {
            int new_one = max(zero - prices[index], one);
            int new_zero = max(one + prices[index], zero);
            one = new_one;
            zero = new_zero;
        }
        return one;
    }
};