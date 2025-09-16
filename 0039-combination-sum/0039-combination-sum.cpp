class Solution {
public:
    int n;
    int total;
    vector<vector<int>> ans;
    void recur(int &index, vector<int>&temp, int &sum,vector<int>& candidates){
        if(sum>total)return;
        if(index==n){
            if(sum==total){
                ans.push_back(temp);
            }
            return;
        }
        index++;
        recur(index,temp,sum,candidates);
        index--;
        temp.push_back(candidates[index]);
        sum += candidates[index];
        recur(index,temp,sum,candidates);
        temp.pop_back();
        sum -= candidates[index];
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        total = target;
        vector<int> temp;
        int sum = 0;
        int index = 0;
        recur(index,temp,sum,candidates);
        return ans;
    }
};