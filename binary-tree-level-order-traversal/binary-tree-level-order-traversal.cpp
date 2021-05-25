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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> queue;
        vector<vector<int>> level_order;
        queue.push(root);
        
        while(!queue.empty())
        {
            int level_size = queue.size();
            vector<int> level;
            for(int i = 0; i < level_size; i++)
            {
                TreeNode* current = queue.front();
                queue.pop();
                
                //process
                level.push_back(current->val);
                
                if(current->left) queue.push(current->left);
                if(current->right) queue.push(current->right);
            }
            level_order.push_back(level);
        }
        
        return level_order;
    }
};