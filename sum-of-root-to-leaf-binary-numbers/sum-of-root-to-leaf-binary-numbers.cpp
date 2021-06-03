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
    void recurse(TreeNode* node, int current_sum, int& sum)
    {
        if(!node) return;
        
        current_sum = (current_sum*2 + node->val);
        if(!node->left && !node->right) sum += current_sum;
        recurse(node->left, current_sum, sum);
        recurse(node->right, current_sum, sum);
    }
    int sumRootToLeaf(TreeNode* root) 
    {
        int sum = 0;
        recurse(root, 0, sum);
        return sum;
    }
};

//5