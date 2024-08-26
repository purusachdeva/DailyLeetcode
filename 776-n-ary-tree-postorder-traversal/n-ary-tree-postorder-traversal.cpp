/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void helper(Node* root, vector<int>& vec) {
        if (!root) return;

        for (auto child : root->children) {
            helper(child, vec);
        }

        vec.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> vec;
        helper(root, vec);

        return vec;
    }
};