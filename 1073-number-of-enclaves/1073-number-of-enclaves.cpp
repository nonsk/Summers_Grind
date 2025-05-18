class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        queue<pair<int, int>> q;
        
        // Add all boundary land cells to the queue
        for (int i = 0; i < rows; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if (grid[i][cols - 1] == 1) {
                q.push({i, cols - 1});
                vis[i][cols - 1] = 1;
            }
        }

        for (int j = 0; j < cols; j++) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                vis[0][j] = 1;
            }
            if (grid[rows - 1][j] == 1) {
                q.push({rows - 1, j});
                vis[rows - 1][j] = 1;
            }
        }
        
        // BFS to mark all land cells connected to boundary
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            for (auto [dx, dy] : dir) {
                int ni = i + dx, nj = j + dy;
                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && 
                    grid[ni][nj] == 1 && vis[ni][nj] == 0) {
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
        
        // Count unmarked land cells
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};