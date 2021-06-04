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
    void recurse(TreeNode* node, double target, int& closest)
    {
        if(!node) return;
        
        if(abs(node->val - target) < abs(closest - target))
            closest = node->val;
        
        if(target > node->val) recurse(node->right, target, closest);
        if(target < node->val) recurse(node->left, target, closest);
    }
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        recurse(root, target, closest);
        return closest;
    }
};