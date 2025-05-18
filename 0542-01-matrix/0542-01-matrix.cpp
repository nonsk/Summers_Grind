class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        vector<vector<int>> ans(mat.size(),
                                vector<int>(mat[0].size(), INT_MAX));
        vector<vector<int>> vis(mat.size() + 1,
                                vector<int>(mat[0].size() + 1, 0));

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();
            int i = node.first;
            int j = node.second;
            vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            int m = INT_MAX;
            for (auto [dx, dy] : dir) {
                int ni = i + dx, nj = j + dy;
                if (ni >= 0 && ni < mat.size() && nj >= 0 &&
                    nj < mat[0].size()) {
                    m = min(m, ans[ni][nj]);
                    if (!vis[ni][nj]) {
                        q.push({ni, nj});
                        vis[ni][nj] = 1;
                    }
                }
            }
            if(ans[i][j]==INT_MAX){ans[i][j] = m + 1;}
        }
        return ans;
    }
};
