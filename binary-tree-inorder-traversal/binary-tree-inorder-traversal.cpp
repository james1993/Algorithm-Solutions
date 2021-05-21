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
    void recurse(TreeNode* node, vector<int>& values)
    {
        if(!node) return;
        
        recurse(node->left, values);
        values.push_back(node->val);
        recurse(node->right, values);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;
        recurse(root, values);
        return values;
    }
};