class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> ans(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        ans[k] = 0;
        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            if (dist > ans[node])
                continue;

            for (auto it : times) {
                if (it[0] == node) {
                    int v = it[1];
                    int w = it[2];
                    if (ans[v] > ans[node] + w) {
                        ans[v] = ans[node] + w;
                        pq.push({ans[v], v});
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (ans[i] == INT_MAX)
                return -1;
            res = max(res, ans[i]);
        }
        return res;
    }
};