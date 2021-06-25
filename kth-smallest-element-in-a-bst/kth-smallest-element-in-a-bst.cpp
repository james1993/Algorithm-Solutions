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
    void recurse(TreeNode* node, int k, int& current, int& element)
    {
        if(!node) return;
        
        recurse(node->left, k, current, element);
        current++;
        if(current == k) element = node->val;
        recurse(node->right, k, current, element);
    }
    int kthSmallest(TreeNode* root, int k) {
        int element = 0;
        int current = 0;
        recurse(root, k, current, element);
        return element;
        
    }
};