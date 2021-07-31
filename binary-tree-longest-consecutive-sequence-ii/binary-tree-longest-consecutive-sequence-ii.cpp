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
    vector<int> recurse(TreeNode* root, int& max_val)
    {
        if(!root) return {0,0};
        int inr = 1;
        int dcr = 1;
        
        if(root->left)
        {
            vector<int> left = recurse(root->left, max_val);
            if(root->val == root->left->val+1) dcr = left[1] + 1;
            else if(root->val == root->left->val - 1) inr = left[0] + 1;
        }
        if(root->right)
        {
            vector<int> right = recurse(root->right, max_val);
            if(root->val == root->right->val+1) dcr = max(dcr,right[1] + 1);
            else if(root->val == root->right->val - 1) inr = max(inr,right[0] + 1);
        }
        max_val = max(max_val,dcr+inr-1);
        return {inr,dcr};
    }
    int longestConsecutive(TreeNode* root) {
        int max_val = 0;
        recurse(root, max_val);
        return max_val;
    }
};