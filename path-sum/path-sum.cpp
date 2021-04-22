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
    
    void dfs(TreeNode* node, int targetSum, bool& has_path)
    {
        if(!node) return;
        
        if(targetSum - node->val == 0 && !node->left && !node->right) 
            has_path = true;
        
        dfs(node->left, targetSum - node->val, has_path);
        dfs(node->right, targetSum - node->val, has_path);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool has_path = false;
        dfs(root, targetSum, has_path);
        return has_path;
    }
};