/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(!slow || !slow->next) return NULL;
        
        do{slow = slow->next; fast = fast->next->next;}
        while(fast && fast->next && slow != fast);
        
        slow = head;
        while(fast && slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};