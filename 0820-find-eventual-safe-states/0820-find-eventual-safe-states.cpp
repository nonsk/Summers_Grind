class Solution {
public:
    bool dfs(int node, const vector<vector<int>>& graph, char state[]) {
        if (state[node]) return state[node] == 2;
        state[node] = 1;
        for (int nei : graph[node]) {
            if (state[nei] == 2) continue;
            if (state[nei] == 1 || !dfs(nei, graph, state)) return false;
        }
        state[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(const vector<vector<int>>& graph) {
        const int n = graph.size();
        char state[10000] = {}; // use raw array instead of vector
        vector<int> result;
        result.reserve(n);

        for (int i = 0; i < n; ++i)
            dfs(i, graph, state);

        for (int i = 0; i < n; ++i)
            if (state[i] == 2)
                result.push_back(i);

        return result;
    }
};
