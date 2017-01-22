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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *head=NULL;

        if(l2->val<l1->val)
        {
            head=l2;
            l2=l2->next;
        }
        else
        {
            head=l1;
            l1=l1->next;
        }
        ListNode *newl=head;

        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                newl->next=l1;
                newl=l1;
                l1=l1->next;
            }
            else 
            {
                newl->next=l2;
                newl=l2;
                l2=l2->next;
            }
        }
        if(l1==NULL)
            newl->next=l2;
        if(l2==NULL)
            newl->next=l1;
        return head;
    }
};