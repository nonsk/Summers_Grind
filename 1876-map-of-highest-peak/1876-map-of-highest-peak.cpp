class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> q;
        vector<vector<int>> ans(isWater.size(),
                                vector<int>(isWater[0].size(), INT_MAX));
        vector<vector<int>> vis(isWater.size(),
                                vector<int>(isWater[0].size(), 0));
         
        for (int i = 0; i < isWater.size(); i++) {
            for (int j = 0; j < isWater[0].size(); j++) {
                if (isWater[i][j] == 1) { 
                    ans[i][j] = 0;
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            int i = node.first;
            int j = node.second;
            
            for (auto [dx, dy] : dir) {
                int ni = i + dx, nj = j + dy;
                if (ni >= 0 && ni < isWater.size() && nj >= 0 &&
                    nj < isWater[0].size() && !vis[ni][nj]) {
                    ans[ni][nj] = ans[i][j] + 1;
                    q.push({ni, nj});
                    vis[ni][nj] = 1;
                }
            }
        }
        return ans;
    }
};