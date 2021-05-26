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
    int recurse(TreeNode* root, int& diameter)
    {
       if(!root) return 0;
        
        int left = recurse(root->left, diameter);
        int right = recurse(root->right, diameter);
        
        diameter = max(diameter, left + right);
        cout << "Visited node " << root->val << ". Current max diameter: " << diameter << "\n";
        return max(left, right) + 1;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        recurse(root, diameter);
        return diameter;
    }
};