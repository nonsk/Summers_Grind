class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> inDegree(n, 0);

        // Build reverse graph and count in-degrees
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                reverseGraph[v].push_back(u);
                inDegree[u]++;
            }
        }

        queue<int> q;
        // Start with terminal nodes (original graph)
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<bool> safe(n, false);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (int neighbor : reverseGraph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (safe[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};
