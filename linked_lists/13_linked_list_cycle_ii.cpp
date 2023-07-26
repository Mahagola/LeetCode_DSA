// https://leetcode.com/problems/linked-list-cycle-ii/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast=head;
        //using fast and slow pointers to detect the cycle
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)break;
        }
        if(!fast||!fast->next)return NULL; //if there's no node return null
        ListNode*slow2=head; //declared another pointer to get the head of the cycle
        while(slow2!=slow){ 
            slow=slow->next;
            slow2=slow2->next;
        }
        return slow;
    }
};