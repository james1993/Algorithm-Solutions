/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        //find middle of linked list
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //reverse the second half
        ListNode* prev = NULL;
        while(slow != NULL)
        {
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
    
        //iterate and check for palindromic property
        while(head != NULL && prev != NULL)
        {
            if (head->val != prev->val) 
                return false;
            head = head->next;
            prev = prev->next;
            if(prev == head) break;
        }
        
        return true;
    }
};