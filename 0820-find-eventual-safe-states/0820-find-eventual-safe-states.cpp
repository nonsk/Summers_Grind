class Solution {
public:
    bool dfs(int node, vector<int>& state, const vector<vector<int>>& graph) {
        if (state[node] > 0) return state[node] == 2;
        state[node] = 1; // Mark as visiting
        for (int next : graph[node]) {
            if (state[next] == 2) continue;     // Already known safe
            if (state[next] == 1 || !dfs(next, state, graph)) return false;
        }
        state[node] = 2; // Mark as safe
        return true;
    }
    vector<int> eventualSafeNodes(const vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); // 0 = unvisited
        vector<int> result;
        result.reserve(n); // Avoid dynamic resizing
        for (int i = 0; i < n; ++i) {
            if (dfs(i, state, graph)) {
                result.push_back(i);
            }
        }
        return result;
    }
};
