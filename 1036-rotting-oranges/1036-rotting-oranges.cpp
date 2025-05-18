class Solution {
public:
    void fill(queue<pair<int, int>>& q, queue<pair<int, int>>& q1,
              vector<vector<int>>& vis, vector<vector<int>>& grid) {
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            // south
            if (node.first + 1 < grid.size() &&
                vis[node.first + 1][node.second] == 0 &&
                grid[node.first + 1][node.second] == 1) {
                q1.push({node.first + 1, node.second});
                vis[node.first + 1][node.second] = 1;
            }
            // east
            if (node.second + 1 < grid[0].size() &&
                vis[node.first][node.second + 1] == 0 &&
                grid[node.first][node.second + 1] == 1) {
                q1.push({node.first, node.second + 1});
                vis[node.first][node.second + 1] = 1;
            }
            // west
            if (node.first - 1 >= 0 && vis[node.first - 1][node.second] == 0 &&
                grid[node.first - 1][node.second] == 1) {
                q1.push({node.first - 1, node.second});
                vis[node.first - 1][node.second] = 1;
            }
            // north
            if (node.second - 1 >= 0 && vis[node.first][node.second - 1] == 0 &&
                grid[node.first][node.second - 1] == 1) {
                q1.push({node.first, node.second - 1});
                vis[node.first][node.second - 1] = 1;
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size() + 1,
                                vector<int>(grid[0].size() + 1, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        if (q.empty()) {
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == 1) {
                        return -1;
                    }
                }
            }
            return 0;
        }
        queue<pair<int, int>> q2;
        int ans = 0;
        while (!q.empty() || !q2.empty()) {
            if (q.empty()) {
                fill(q2, q, vis, grid);
            } else {
                fill(q, q2, vis, grid);
            }
            ans++;
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    return -1;
                }
            }
        }
        return ans - 1;
    }
};