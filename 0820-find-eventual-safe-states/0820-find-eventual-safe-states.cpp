class Solution {
public:
    // 0 = unvisited, 1 = visiting, 2 = safe
    bool dfs(int node, vector<int>& state, vector<vector<int>>& graph) {
        if (state[node] != 0) {
            return state[node] == 2;
        }

        state[node] = 1; // Mark as visiting

        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, state, graph)) {
                return false; // cycle detected
            }
        }

        state[node] = 2; // Mark as safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); // 0=unvisited, 1=visiting, 2=safe
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (dfs(i, state, graph)) {
                result.push_back(i);
            }
        }

        return result; // Already in sorted order
    }
};
