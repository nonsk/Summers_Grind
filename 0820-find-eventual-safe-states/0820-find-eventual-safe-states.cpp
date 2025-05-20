class Solution {
public:
    bool dfs(int src,vector<int>&safeNodes,vector<int>&vis,vector<int>&pathVis,vector<vector<int>>& adj){
        vis[src]=1;
        pathVis[src]=1;
        for(int nbr:adj[src]){
            if(!vis[nbr]){
                if(!dfs(nbr,safeNodes,vis,pathVis,adj)) return false;
            }
            else if(pathVis[nbr]) return false;
        }
        safeNodes.push_back(src);
        pathVis[src]=0;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>safeNodes;
        int n=graph.size();
        vector<int>vis(n,false),pathVis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,safeNodes,vis,pathVis,graph);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};