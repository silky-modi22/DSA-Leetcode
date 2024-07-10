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
    ListNode* reverseList(ListNode* head) {
    if(head == NULL || head-> next ==NULL) return head;
    ListNode *curr = head;
    ListNode *prev = NULL;
    while(curr!=NULL){ 
        // Store the next node in 'temp' to preserve the reference
       ListNode *temp = curr->next;
       curr->next = prev;
       // Move 'prev' to the current node for the next iteration
       prev=curr;
       // Move 'curr' to the 'temp' node advancing the traversal
       curr=temp;
       
    }
    return prev;
        
    }
};