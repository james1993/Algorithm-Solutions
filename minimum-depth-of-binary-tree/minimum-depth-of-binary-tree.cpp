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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int depth = 0;
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty())
        {
            int level_size = queue.size();
            depth++;
            for(int i = 0; i < level_size; i++)
            {
                TreeNode* node = queue.front();
                queue.pop();
                
                if(!node->left && !node->right) 
                    return depth;
                
                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }
        }
        
        return depth;
    }
};