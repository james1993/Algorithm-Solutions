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
    void recurse(TreeNode* node, vector<int>& nodes)
    {
        if(!node) return;
        
        recurse(node->left, nodes);
        nodes.push_back(node->val);
        recurse(node->right, nodes);
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> nodes;
        recurse(root, nodes);
        
        int minimum = INT_MAX;
        for(int i = 1; i < nodes.size(); i++)
        {
            minimum = min(minimum, abs(nodes[i]-nodes[i-1]));
        }
        
        return minimum;
    }
};