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
    int pairSum(ListNode* head) {
        ListNode* start=head;
        ListNode* slow=head,*fast=head->next;
        
        while(true){
            if(!fast->next){
                break;
            }
            else{
                fast=fast->next->next;
            }
            slow=slow->next;
            
        }
        
        ListNode* pstart = fast,*curr = slow->next,*currnxt=slow->next->next,*prev=slow;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=currnxt;
            if(currnxt)
            currnxt=currnxt->next;
            
        }
        
        ListNode* end=prev;
        int sum = 0;
        while(start->next!=end || end->next!=start){
            sum = max(sum,start->val+end->val);
            start=start->next;
            end=end->next;
        }
        sum = max(sum,start->val+end->val);
        return sum;
        
        
        
        
        
    }
};