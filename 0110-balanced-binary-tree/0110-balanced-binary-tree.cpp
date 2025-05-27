class Solution {
public:
    int checkHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = checkHeight(root->left);
        if (left == -1) return -1;  // not balanced

        int right = checkHeight(root->right);
        if (right == -1) return -1;  // not balanced

        if (abs(left - right) > 1) return -1;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
