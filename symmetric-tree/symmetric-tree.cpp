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
    void recurse(TreeNode* p, TreeNode* q, bool& symmetric)
    {
        if(!p && !q) return;
        else if((p && !q) || (!p && q)) symmetric = false;
        else
        {
            if(p->val != q->val) symmetric = false;
            recurse(p->left, q->right, symmetric);
            recurse(p->right, q->left, symmetric);
        }
    }
    bool isSymmetric(TreeNode* root) {
        bool symmetric = true;
        recurse(root->left, root->right, symmetric);
        return symmetric;
    }
};