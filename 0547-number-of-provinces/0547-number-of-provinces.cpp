class Solution {
public:
    void bfs(int n, vector<vector<int>>& isConnected, vector<int>& vis) {
        cout << n << endl;
        queue<int> q;
        q.push(n);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < isConnected.size(); i++) {
                if (isConnected[node][i] == 1 && vis[i] == 0) {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int p = 0;
        vector<int> vis(isConnected.size(), 0);
        for (int i = 0; i < vis.size(); i++) {
            if (vis[i] == 0) {
                bfs(i, isConnected, vis);
                p++;
            }
        }
        return p;
    }
};