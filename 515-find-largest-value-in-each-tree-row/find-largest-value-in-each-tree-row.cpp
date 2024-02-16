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

    vector<int> largestValues(TreeNode* root) {
        if(!root) return vector<int>(0);
        queue<TreeNode*> q;

        vector<int> rWiseMax;

        q.push(root);
        while(q.size() != 0) {
            int n = q.size();

            int maxi = INT_MIN;
            while(n != 0) {
                TreeNode* temp = q.front();
                q.pop();

                maxi = max(maxi, temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                n--;
            }

            rWiseMax.push_back(maxi);
        }

        return rWiseMax;
    }
};