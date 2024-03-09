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
    int height(TreeNode* root, bool &f) {
        if(f == false) return 0;
        if(!root) return 0;
        
        int left = 0, right = 0;
        if(root->left) left = height(root->left, f);
        if(root->right) right = height(root->right, f);

        if(abs(left-right) > 1) f = false;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        bool f = true;

        int ht = height(root, f);
        return f;
    }
};