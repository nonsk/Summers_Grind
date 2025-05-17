class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> mini(prices.size(), INT_MAX);
        int m = INT_MAX;
        for(int i =0; i<prices.size(); i++){
            m = min(m,prices[i]);
            mini[i] = m;
            cout<<m<<" ";
        }
        int profit = 0;
        for(int i =prices.size()-1; i>=1; i--){
            profit = max(profit, prices[i] - mini[i-1]);
        }
        return profit;

    }
};