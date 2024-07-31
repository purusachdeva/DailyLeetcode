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
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (p && q && p->val == q->val) 
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        return false;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (isSameTree(root, subRoot)) return true;

        if (root->left &&isSubtree(root->left, subRoot)) return true;
        if (root->right && isSubtree(root->right, subRoot)) return true;

        return false;
    }
};