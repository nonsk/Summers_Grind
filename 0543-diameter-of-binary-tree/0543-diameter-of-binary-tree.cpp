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
    int h(TreeNode* root,int &ans){
        if(!root){
            return 0;
        }
        int lsh = h(root->left,ans);
        int rsh = h(root->right,ans);
        ans = max(ans,lsh+rsh);
        return 1+max(lsh,rsh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        h(root,ans);
        return ans;
    }
};