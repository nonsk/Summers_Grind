class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue <int> q1;
        queue <int> q2;
        for(int i =0; i<nums.size(); i++){
            if(nums[i]<0){
                q1.push(nums[i]);
            }
            else{
                q2.push(nums[i]);
            }
        }
        vector<int> ans;
        while(!q1.empty() && !q2.empty()){
            ans.push_back(q2.front());
            ans.push_back(q1.front());
            q2.pop();
            q1.pop();
        }
        return ans;
    }
};