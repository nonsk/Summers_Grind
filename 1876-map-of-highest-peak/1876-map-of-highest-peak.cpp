class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        deque<int> q; // acts like a queue but supports faster access and optional reserve (if vector used)

        constexpr int dx[4] = {-1, 0, 1, 0};
        constexpr int dy[4] = {0, 1, 0, -1};

        auto idx = [&](int i, int j) -> int { return i * n + j; };

        // Initialize all water cells
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (isWater[i][j]) {
                    ans[i][j] = 0;
                    q.push_back(idx(i, j));
                }

        while (!q.empty()) {
            int k = q.front(); q.pop_front();
            int i = k / n, j = k % n;
            int h = ans[i][j];

            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && ans[ni][nj] == -1) {
                    ans[ni][nj] = h + 1;
                    q.push_back(idx(ni, nj));
                }
            }
        }

        return ans;
    }
};
