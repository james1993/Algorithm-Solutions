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
    void recurse(TreeNode* node, vector<int>& sorted_array)
    {
        if(!node) return;
        
        recurse(node->left, sorted_array);
        sorted_array.push_back(node->val);
        recurse(node->right, sorted_array);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> sorted_array;
        recurse(root, sorted_array);
        
        int first = 0;
        int last = sorted_array.size() - 1;
        while(first < last)
        {
            int sum = sorted_array[first] + sorted_array[last];
            if(sum > k) last--;
            else if(sum < k) first++;
            else return true; //sum == k
        }
        return false;
    }
};