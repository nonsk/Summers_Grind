class Solution {
public:
    map<pair<int,int>,int> mp;
    int recur(int l, int r, vector<int>& cuts) {
        if(mp.find({l,r})!=mp.end())return mp[{l,r}];
        int ans = INT_MAX;
        int from = upper_bound(cuts.begin(), cuts.end(), l) - cuts.begin();
        int to = lower_bound(cuts.begin(), cuts.end(), r) - cuts.begin();
        for (int i = from; i <to; i++) {
            int mid = cuts[i];
            ans = min(ans, recur(l, mid, cuts) + recur(mid, r,cuts) + r - l);
        }
        if (ans == INT_MAX)
            ans = 0;
        return mp[{l,r}] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        return recur(0, n,cuts);
    }
};