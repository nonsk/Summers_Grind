class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<pair<int, TreeNode*>> q;
        q.push({0, root});

        while (!q.empty()) {
            auto [lvl, node] = q.front();
            q.pop();

            if (ans.size() == lvl)
                ans.push_back({});

            ans[lvl].push_back(node->val);

            if (node->left)
                q.push({lvl + 1, node->left});
            if (node->right)
                q.push({lvl + 1, node->right});
        }

        return ans;
    }
};
