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
    void recurse(TreeNode* node, vector<int>& vals)
    {
        if(!node) return;
        vals.push_back(node->val);
        
        int L = node->left ? node->left->val : -1;
        int R = node->right ? node->right->val : -1;
        if(L < R)
        {
            recurse(node->right, vals);
            recurse(node->left, vals);
        }
        else
        {
            recurse(node->left, vals);
            recurse(node->right, vals);
        }
        vals.push_back(NULL);
        
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> vals1;
        vector<int> vals2;
        recurse(root1, vals1);
        recurse(root2, vals2);
        return vals1 == vals2;
    }
};