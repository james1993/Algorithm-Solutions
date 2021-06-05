/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    
    void recurse(Node* node, Node*& first, Node*& last)
    {
        if(!node) return;
        
        recurse(node->left, first, last);
        
        if(last)
        {
            last->right = node;
            node->left = last;
        }
        else
            first = node;
        last = node;
        
        recurse(node->right, first, last);
    }
    Node* treeToDoublyList(Node* root) 
    {
        if(!root) return NULL;
        
        Node* first = NULL;
        Node* last = NULL;
        
        recurse(root, first, last);
        
        last->right = first;
        first->left = last;
        
        return first;
    }
};