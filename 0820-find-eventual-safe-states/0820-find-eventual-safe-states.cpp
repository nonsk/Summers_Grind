class Solution {
public:
    vector<int> eventualSafeNodes(const vector<vector<int>>& graph) {
        int n = graph.size();
        vector<char> state(n, 0); // 0: unvisited, 1: visiting, 2: safe
        vector<int> result;
        result.reserve(n); // Avoid dynamic resize

        auto dfs = [&](int node, auto&& dfs_ref) -> bool {
            if (state[node]) return state[node] == 2;
            state[node] = 1; // visiting
            for (int nei : graph[node]) {
                if (state[nei] == 2) continue;
                if (state[nei] == 1 || !dfs_ref(nei, dfs_ref)) return false;
            }
            state[node] = 2;
            result.push_back(node);
            return true;
        };

        for (int i = 0; i < n; ++i) dfs(i, dfs);
        sort(result.begin(), result.end()); // optional if order required
        return result;
    }
};
