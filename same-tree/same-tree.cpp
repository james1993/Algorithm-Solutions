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
    
    void dfs(TreeNode* p, TreeNode* q, bool& is_same)
    {
        if(!p && !q) return;
        if((p && !q) || (q && !p) || (p->val != q->val))
        {
            is_same = false;
            return;
        }
        
        dfs(p->left, q->left, is_same);
        dfs(p->right, q->right, is_same);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool is_same = true;
        dfs(p, q, is_same);
        return is_same;
    }
};