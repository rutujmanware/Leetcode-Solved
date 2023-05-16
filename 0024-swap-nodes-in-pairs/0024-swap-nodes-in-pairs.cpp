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
    ListNode* swapPairs(ListNode* head) {
        if(!head){
            return NULL;
        }
        if(!head->next){
            return head;
        }
        ListNode* prev=NULL, *curr = head, *curr1 = head->next;
        
        while(curr?curr->next:curr){
            if(prev){
                prev->next = curr1;
            }
            if(curr1)
            curr->next=curr1->next;
            if(curr1)
            curr1->next=curr;
            if(!prev){
                head=curr1;
            }
            prev = curr;
            
            curr=curr->next;
            if(curr)
            curr1 = curr->next;
            
        }
        return head;
    }
};