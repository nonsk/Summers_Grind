class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &temp,vector<vector<int>>& graph, int start, int &n ){
        // cout<<start<<endl;
        if(start==n-1){
            ans.push_back(temp);
            return;
        }
        for(int i =0; i<graph[start].size(); i++){
            temp.push_back(graph[start][i]);
            dfs(ans, temp, graph, graph[start][i], n);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = graph.size();
        temp.push_back(0);
        dfs(ans,temp,graph, 0, n);
        return ans;
    }
};