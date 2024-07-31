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
    pair<int, bool> height(TreeNode* root) {
        if (!root) return {0, true};

        pair<int, bool> left = height(root->left);
        if (!left.second) return {0, false};
        pair<int, bool> right = height(root->right);
        if (!right.second) return {0, false};

        if (abs(left.first - right.first) > 1) return {0, false};

        return {1 + max(left.first, right.first), true};
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        return height(root).second;
    }
};