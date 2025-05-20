class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        const int INF = 1e9;
        vector<vector<int>> ans(n,vector<int>(n,INF));
        queue<pair<pair<int,int>,int>> q;
        if(grid[0][0] == 1)return -1;
        q.push({{0,0},1});
        ans[0][0] = 1;
        vector<pair<int,int>> d = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        while(!q.empty()){
            auto [p,dist] = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();

            for(int i = 0;i < 8;i++){
                int nx = x + d[i].first;
                int ny = y + d[i].second;
                if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                    if(grid[nx][ny] != 1 && dist + 1 <ans[nx][ny]){
                        ans[nx][ny] = 1 + dist;
                        q.push({{nx,ny},1 + dist});
                    }
                }
            }
        }


        return ans[n - 1][n - 1] != INF?ans[n - 1][n - 1]:-1;

    }
};