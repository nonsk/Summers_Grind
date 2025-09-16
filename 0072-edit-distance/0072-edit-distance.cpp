class Solution {
public:
    vector<vector<int>> dp;
    int n,m;
    int recur(int i, int j, string &word1, string &word2){
        if(i==n)return m-j;
        if(j==m)return n-i;
        // transition

        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j]) return recur(i+1,j+1,word1,word2);
        //insert
        int ins = recur(i,j+1,word1,word2)+1;
        //deletion
        int del = recur(i+1,j,word1,word2)+1;
        //replace
        int rep = recur(i+1,j+1,word1,word2)+1;

        return dp[i][j] = min({ins,del,rep});
    }
    int minDistance(string word1, string word2) {
        
        n = word1.size();
        m = word2.size();
        dp.assign(n,vector<int>(m,-1));
        return recur(0,0,word1,word2);
    }
};