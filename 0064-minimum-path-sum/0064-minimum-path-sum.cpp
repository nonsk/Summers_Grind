class Solution {
public:
    vector<vector<int>> dp;
    int n,m;
    int recur(int i, int j, vector<vector<int>>& grid){
        if(i<0 || j<0)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        int up = recur(i-1,j,grid);
        int left = recur(i,j-1,grid);
        dp[i][j] = min(up,left) + grid[i][j];
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n+1,vector<int>(m+1,-1));
        dp[0][0] = grid[0][0];
        return recur(n-1, m-1, grid);
    }
};