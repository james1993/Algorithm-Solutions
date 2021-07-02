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
    void recurse(TreeNode*& node, vector<int>& leaves)
    {
        if(!node) return;
        
        if(!node->left && !node->right) 
        {
            leaves.push_back(node->val);
            node = NULL;
        }
        else
        {
            recurse(node->left, leaves);
            recurse(node->right, leaves);
        }
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        
        while(root) 
        {
            vector<int> leaves;
            recurse(root, leaves);
            result.push_back(leaves);
        }
        
        return result;
    }
};