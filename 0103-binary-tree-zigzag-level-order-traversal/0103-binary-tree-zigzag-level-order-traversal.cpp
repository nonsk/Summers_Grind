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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue < pair < int, TreeNode* >> q;
        q.push({0, root});
        while (!q.empty()) {
            auto [lvl, node] = q.front();
            q.pop();
            if (lvl >= ans.size()) {
                ans.push_back({});
            }
            ans[lvl].push_back(node->val);
            if (node->right != nullptr) {
                q.push({lvl + 1, node->right});
            }
            if (node->left != nullptr) {
                q.push({lvl + 1, node->left});
            }
        }
        for(int i =0; i<ans.size(); i=i+2){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};