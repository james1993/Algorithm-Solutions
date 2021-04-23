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
    
    void dfs(TreeNode* left_node, TreeNode* right_node, bool& is_symmetric)
    {
        if(!left_node && !right_node) return;
        if(!left_node || !right_node) 
        {
            is_symmetric = false;
            return;
        }
        
        if(left_node->val != right_node->val) 
        {
            is_symmetric = false;
            return;
        }
        dfs(left_node->left, right_node->right, is_symmetric);
        dfs(left_node->right, right_node->left, is_symmetric);
    }
    
    bool isSymmetric(TreeNode* root) {
        bool is_symmetric = true;
        dfs(root->left, root->right, is_symmetric);
        return is_symmetric;
    }
};