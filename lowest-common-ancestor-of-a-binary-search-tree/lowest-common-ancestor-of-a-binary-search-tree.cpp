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
    void recurse(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& lca)
    {
        if(!node) return;
        
        if(p->val <= node->val && q->val >= node->val && !lca) 
            lca = node;
        else
        {
            recurse(node->left, p, q, lca);
            recurse(node->right, p, q, lca);
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* lca = NULL;
        TreeNode* lesser = NULL;
        TreeNode* greater = NULL;
        
        
        if(p->val < q->val)
        {
            lesser = p;
            greater = q;
        }
        else
        {
            lesser = q;
            greater = p;
        }
        
        recurse(root, lesser, greater, lca);
        return lca;
    }
};