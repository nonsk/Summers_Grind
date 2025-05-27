/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void pre(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) {
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->val);
        pre(root->left, ans);
        pre(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        pre(root, ans);
        return ans;
    }
    void in(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) {
            ans.push_back(-1);
            return;
        }
        in(root->left, ans);
        ans.push_back(root->val);
        in(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        in(root, ans);
        return ans;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pre1 = preorderTraversal(p);
        vector<int> pre2 =preorderTraversal(q);
        vector<int> in1 = inorderTraversal(p);
        vector<int> in2 = inorderTraversal(q);
        if(pre1==pre2 && in1==in2){
            return true;
        }
        return false;
    }
};