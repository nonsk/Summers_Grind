class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] != 1) {
            return;
        }
        grid[i][j] = -1;

        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto [dx, dy] : dir) {
            dfs(i + dx, j + dy, grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            if (grid[i][0] == 1)
                dfs(i, 0, grid);
            if (grid[i][cols - 1] == 1)
                dfs(i, cols - 1, grid);
        }

        for (int j = 0; j < cols; j++) {
            if (grid[0][j] == 1)
                dfs(0, j, grid);
            if (grid[rows - 1][j] == 1)
                dfs(rows - 1, j, grid);
        }
        int ans=0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == -1) {
                    ans++;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans +=grid[i][j];
            }
        }
        return ans;
    }
};