
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p2=head,*p1=head;
        for(int i=0;i<n;i++)
            p2=p2->next;
        if(p2==NULL)
        {
            head=head->next;
            return head;
        }
        p2=p2->next;
        while(p2!=NULL)
        {
            p2=p2->next;
            p1=p1->next;
        }
        p1->next=p1->next->next;
        return head;
    }
};