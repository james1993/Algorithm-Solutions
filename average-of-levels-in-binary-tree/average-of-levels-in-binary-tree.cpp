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

/*
        while(!q.empty()) {
            long temp=0;
            int s=q.size();
            for(int i=0;i<s;i++) {
                TreeNode* t=q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                temp+=t->val;
            }
            res.push_back((double)temp/s);
        }
        return res;
*/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty())
        {
            int level_size = queue.size();
            long sum = 0;
            
            for(int i = 0; i < level_size; i++)
            {
                TreeNode* curr = queue.front();
                queue.pop();
                
                sum += curr->val;
                
                if(curr->left) queue.push(curr->left);
                if(curr->right) queue.push(curr->right);
            }
            averages.push_back((double)sum/level_size);
        }
        
        return averages;
    }
};