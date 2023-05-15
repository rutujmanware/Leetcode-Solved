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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* start,* end;
        start = head;
        end = head;
        // cout<<head->val<<endl;
        int x=0;
        while(x!=k-1){
            start=start->next;
            x++;
        }
        int count=0;
        while(end){
            end=end->next;
            count++;
        }
        // count;
        count=count-k;
        end = head;
        while(count--){
            end = end->next;
        }
        // cout<<end->val<<endl;
        // cout<<start->val;
        swap(start->val,end->val);
        return head;
    }
};