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
    
    void recurse(TreeNode* node, int current_depth, int& max_depth)
    {
        if(!node) return;
        
        current_depth++;
        max_depth = max(max_depth, current_depth);
        
        recurse(node->left, current_depth, max_depth);
        recurse(node->right, current_depth, max_depth);
    }
    
    int maxDepth(TreeNode* root) 
    {
        int max_depth = 0;
        recurse(root, 0, max_depth);
        return max_depth;
    }
};