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
    
    void dfs(TreeNode* node, int& max_depth, int current_depth)
    {
        if(!node) return;
        
        max_depth = max(max_depth, current_depth);
        dfs(node->left, max_depth, current_depth+1);
        dfs(node->right, max_depth, current_depth+1);
    }
    
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        dfs(root, max_depth, 1);
        return max_depth;
    }
};