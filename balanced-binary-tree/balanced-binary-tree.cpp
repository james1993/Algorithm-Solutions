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
    int recurse(TreeNode* node, bool& balanced)
    {
        if(!node) return 0;
        
        int left = recurse(node->left, balanced);
        int right = recurse(node->right, balanced);
        
        if(abs(left-right) > 1) balanced = false;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        recurse(root, balanced);
        return balanced;
    }
};