class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1; // Mark as visiting
        for (auto u : adj[node]) {
            if (vis[u] == 0) {
                if (!dfs(u, adj, vis)) return false;
            } else if (vis[u] == 1) {
                // Found a back edge — cycle detected
                return false;
            }
        }
        vis[node] = 2; // Mark as visited
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);

        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); // Directed edge: it[1] → it[0]
        }

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (!dfs(i, adj, vis)) return false;
            }
        }

        return true;
    }
};
