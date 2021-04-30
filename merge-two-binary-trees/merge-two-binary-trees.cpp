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
    
    void recurse(TreeNode* node1, TreeNode* node2, TreeNode*& new_tree)
    {
        if(!node1 && !node2) 
            new_tree = NULL;
        else if(node1 && !node2)
            new_tree = node1;
        else if(node2 && !node1)
            new_tree = node2;
        else
        {
            TreeNode* new_node = new TreeNode(node1->val + node2->val);
            new_tree = new_node;
        
            recurse(node1->left, node2->left, new_tree->left);
            recurse(node1->right, node2->right, new_tree->right);
        }
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* new_tree = new TreeNode();
        recurse(root1, root2, new_tree);
        return new_tree;
    }
};