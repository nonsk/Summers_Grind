class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        
        map<pair<int, int>, vector<pair<int, int>>> mp;
        vector<pair<int, int>> dir = {{0, 1},  {1, 0}, {0, -1}, {-1, 0},
                                      {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
        map<pair<int, int>, bool> vis;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    vis[{i, j}] = false;
                    for (auto [dx, dy] : dir) {
                        int ndx = dx + i;
                        int ndy = dy + j;
                        if (ndx >= 0 && ndx < n && ndy >= 0 && ndy < n &&
                            grid[ndx][ndy] == 0) {
                            mp[{i, j}].push_back({ndx, ndy});
                        }
                    }
                }
            }
        }
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[{0, 0}] = true;
        int lvl = 1; 
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> u = q.front();
                q.pop();
                
                
                if (u.first == n-1 && u.second == n-1) {
                    return lvl;
                }
                
                for (auto [iu, ju] : mp[u]) {
                    if (!vis[{iu, ju}]) {
                        q.push({iu, ju});
                        vis[{iu, ju}] = true;
                    }
                }
            }
            lvl++; 
        }
        
        return -1; 
    }
};