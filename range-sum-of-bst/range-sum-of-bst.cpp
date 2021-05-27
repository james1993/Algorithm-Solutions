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
    
    void recurse(TreeNode* node, int low, int high, int& sum)
    {
        if(!node) return;
        
        if(node->val <= high && node->val >= low) sum += node->val;
        cout <<"Just visited " << node->val << ". New sum: " << sum << "\n";
        
        if(node->val > low)
            recurse(node->left, low, high, sum);
        if(node->val < high)
            recurse(node->right, low, high, sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        recurse(root, low, high, sum);
        return sum;
    }
};