class Solution {
public:
    int last;
    vector<vector<int>>dp;
    int recur(int index, int k, vector<int>& stones) {
        if (index == last)
            return 1;
        if(dp[index][k]!=-1)return dp[index][k];
        int ans = 0;

        for (int i = index + 1; i <=last; i++) {
            int jump = stones[i] - stones[index];
            if (jump > k + 1) {
                break;
            }
            if (jump == k || jump == k - 1 || jump == k + 1) {
                ans = (ans || recur(i,jump,stones));
                if(ans==1)break;
            }
        }
        dp[index][k] = ans;
        return ans;
    }
    bool canCross(vector<int>& stones) {
        last = stones.size() - 1;
        dp.assign(last+1,vector<int>(last+1,-1));
        if(stones[1]!=1)return false;
        return recur(1, 1, stones);
    }
};