class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int recur(int i , int j, vector<vector<int>>& obstacleGrid){
        if(i>=n || j>=m) return 0;
        if(obstacleGrid[i][j]==1)return 0;
        if(i==n-1 && j==m-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        dp[i][j] =  recur(i+1,j,obstacleGrid) + recur(i,j+1,obstacleGrid);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size(); m = obstacleGrid[0].size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return recur(0,0,obstacleGrid);
    }
};