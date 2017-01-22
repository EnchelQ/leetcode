
//beats 0.17%
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
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *cur=head;
        ListNode *pre=head;
        ListNode* next=cur->next->next;//为cur暂存值
        head=head->next;
        cur->next->next=cur;
        cur=next;
        
        while(cur!=NULL && cur->next!=NULL)
        {
            ListNode* next=cur->next->next;////为cur暂存值
            pre->next=cur->next;//前头链好
            cur->next->next=cur;//调转
            pre=cur;
            cur=next;
        }
        pre->next=cur;
        return head;
    }
};



//beats 0.17%
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* present_pair=head;
        head=head->next;
        ListNode* next_pair=head->next;
        while(next_pair!=NULL && next_pair->next!=NULL)
        {
            present_pair->next->next=present_pair;
            present_pair->next=next_pair->next;
            present_pair=next_pair;
            next_pair=next_pair->next->next;
        }
        present_pair->next->next=present_pair;
        present_pair->next=next_pair;
        return head;    
            
    }
};