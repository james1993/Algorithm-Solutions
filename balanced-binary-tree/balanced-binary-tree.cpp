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
    
    int dfs(TreeNode* node, bool& is_balanced)
    {
        if(!node) return 0;
        
        int left_height = dfs(node->left, is_balanced);
        int right_height = dfs(node->right, is_balanced);
        
        if(abs(left_height - right_height) > 1) is_balanced = false;
        return max(left_height, right_height) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        bool is_balanced = true;
        dfs(root, is_balanced);
        return is_balanced;
    }
};