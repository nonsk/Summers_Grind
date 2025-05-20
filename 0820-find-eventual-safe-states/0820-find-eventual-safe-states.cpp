class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& graph,
             vector<int>& recur_record, vector<int>& ans) {
        vis[node] = true;
        recur_record[node] = true;
        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (!dfs(it, vis, graph, recur_record, ans)) {
                    return false;
                }
            }
            if (recur_record[it]) {
                return false;
            }
        }
        recur_record[node] = false;
        ans.push_back(node);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> recur_record(graph.size(), false);
        vector<int> vis(graph.size(), false);
        vector<int> ans;
        for (int i = 0; i < graph.size(); i++) {
            if (!vis[i]) {
                dfs(i, vis, graph, recur_record, ans);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};