/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr){
            return ans;
        }
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        while(!q.empty()){
            auto [lvl,node] = q.front();
            q.pop();
            if(lvl>=ans.size()){
                ans.push_back(0);
            }
            ans[lvl] = node->val;

            if(node->left!=nullptr){
                q.push({lvl+1,node->left});
            }
            if(node->right!=nullptr){
                q.push({lvl+1,node->right});
            }

        }
        return ans;
    }
};