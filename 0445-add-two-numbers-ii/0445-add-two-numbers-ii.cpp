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
ListNode* reverse(ListNode* l){
    ListNode* curr=l;
    ListNode* prev=NULL;
    while(curr!=NULL){
        ListNode* front=curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }
    return prev;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1=reverse(l1);
        ListNode* h2=reverse(l2);
        int carry=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(h1|| h2|| carry){
            int x=(h1!=NULL)?h1->val:0;
            int y=(h2!=NULL)?h2->val:0;
            int sum=x+y+carry;
            temp->next=new ListNode(sum%10);
            carry=sum/10;
            temp=temp->next;
            h1=(h1!=NULL)?h1->next:NULL;
            h2=(h2!=NULL)?h2->next:NULL;
        }
        reverse(dummy->next);
        return temp;
    }
};