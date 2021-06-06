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

    void recurse(TreeNode* node, TreeNode* subNode, bool& is_sub)
    {
        if(!node && !subNode) return;
        if(!node || !subNode) 
        {
            is_sub = false;
            return;
        }
        
        if(node->val != subNode->val) is_sub = false;
        
        recurse(node->left, subNode->left, is_sub);
        recurse(node->right, subNode->right, is_sub);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return false;
        bool is_sub = false;
        
        if(root->val == subRoot->val)
        {
            is_sub = true;
            recurse(root, subRoot, is_sub);
            if(is_sub) 
                return true;
        }
        //else
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};