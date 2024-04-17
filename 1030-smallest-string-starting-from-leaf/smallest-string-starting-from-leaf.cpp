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

    string smallest = "~";

    bool firstSmaller(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for(int i = 0; i < min(a.length(), b.length()); i++) {
            if(a[i] < b[i]) return true;
            if(a[i] > b[i]) return false;
        }

        if(a.length() > b.length()) return false;
        else return true;
    }

    void dfs(TreeNode* root, string path) {
        // If node is null, return
        if (!root)
            return;

        path += char(root->val + 'a');

        if (!root->left && !root->right) {
            if (firstSmaller(path, smallest))
                smallest = path;
            return;
        }

        dfs(root->left, path);
        dfs(root->right, path);
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        reverse(smallest.begin(), smallest.end());
        return smallest;
    }
};