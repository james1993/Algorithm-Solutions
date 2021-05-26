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
    void recurse(TreeNode* p, TreeNode* q, bool& same)
    {
        if(!p && !q) return;
        else if((p && !q) || (!p && q)) 
            same = false;
        else
        {
            if(p->val != q->val) same = false;
            recurse(p->left, q->left, same);
            recurse(p->right, q->right, same);
        }
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool same = true;
        recurse(p, q, same);
        return same;
    }
};