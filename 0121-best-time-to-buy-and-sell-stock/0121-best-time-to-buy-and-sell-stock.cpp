class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit = max(prices[i] - m,profit);
            m = min(prices[i],m);
        }
        return profit;
    }
};