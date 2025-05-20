class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<pair<int, int>> vis(graph.size(), {0, -1});
        for (int start = 0; start < graph.size(); ++start) {
            if (vis[start].first)
                continue;
            queue<int> q;
            q.push(start);
            vis[start].first = 1;
            vis[start].second = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto it : graph[node]) {
                    if (!vis[it].first) {
                        q.push(it);
                        vis[it] = {1, 1 - vis[node].second};

                    } else {
                        if (vis[it].second == vis[node].second)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};