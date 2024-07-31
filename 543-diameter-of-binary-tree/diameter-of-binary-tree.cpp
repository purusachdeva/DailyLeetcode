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
    int maxi = 0;
    
    int heightExplore(TreeNode* root) {
        if (!root) return 0;

        int a = heightExplore(root->left);
        int b = heightExplore(root->right);
        maxi = max(a + b, maxi);

        return 1 + max(a, b);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        heightExplore(root);
        return maxi;

    }
};