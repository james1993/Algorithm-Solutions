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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        bool met_empty = false;
        while(!queue.empty())
        {
            int level_size = queue.size();
            for(int i = 0; i < level_size; i++)
            {
                TreeNode* current = queue.front();
                queue.pop();
                
                if(met_empty && (current->left || current->right)) return false;
                
                if(current->left) queue.push(current->left);
                else met_empty = true;
                if(current->right && met_empty) return false;
                if(current->right) queue.push(current->right);
                else met_empty = true;
            }
        }
        return true;
    }
};