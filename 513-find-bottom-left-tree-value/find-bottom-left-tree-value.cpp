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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        int element = 0;

        while(q.size() != 0) {
            int n = q.size();

            element = q.front()->val;
            for(int i = 0; i < n; i++) {
                TreeNode* current = q.front();
                q.pop();

                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }

        }
        return element;
    }
};