/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recurse(TreeNode* node, TreeNode* p, TreeNode*& inorder, TreeNode*& prev)
    {
        if(!node) return;
        
        recurse(node->right, p, inorder, prev);
        
        if(node == p) inorder = prev;
        prev = node;
        
        recurse(node->left, p, inorder, prev);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        TreeNode* inorder = NULL;
        TreeNode* prev = NULL;
        recurse(root, p, inorder, prev);
        return inorder;
    }
};