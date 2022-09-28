class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* hell=head,*heaven=head;
        while(n--){
            hell=hell->next;
        }
        ListNode* prev=NULL;
        while(hell){
            hell=hell->next;
            prev=heaven;
            heaven=heaven->next;
            
        }
        if(prev){
            prev->next=heaven->next;
            return head;
        }else{
            return head->next;
        }
        

    }
};