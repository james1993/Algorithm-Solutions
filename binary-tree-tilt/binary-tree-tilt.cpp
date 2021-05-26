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
    int recurse(TreeNode* node, int& tilt)
    {
        if(!node) return 0;
        
        int left = recurse(node->left, tilt);
        int right = recurse(node->right, tilt);
        
        tilt += abs(left-right);
        return left + right + node->val;
        
    }
    int findTilt(TreeNode* root) {
        int tilt = 0;
        recurse(root, tilt);
        return tilt;
    }
};