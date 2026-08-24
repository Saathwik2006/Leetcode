/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int len1=0,len2=0;
    struct ListNode* temp1=l1;
    struct ListNode* temp2=l2;
    struct ListNode* temp=NULL;

    while(temp1!=NULL){
        len1++;
        temp1=temp1->next;
    }
 while(temp2!=NULL){
        len2++;
        temp2=temp2->next;
    }

temp1=l1;
temp2=l2;

if(len2>len1){
    temp=temp1;
    temp1=temp2;
    temp2=temp;

    int l=len1;
    len1=len2;
    len2=l;
}

struct ListNode*sum=NULL;
temp=temp1;
while( temp2!=NULL){
    temp1->val=temp1->val+temp2->val;
    temp2=temp2->next;
    temp1=temp1->next;
}
struct ListNode*head=temp;
while(temp){
    if(temp->val>9){
        if(temp->next){
            temp->val=temp->val-10;
            
            temp->next->val++;
        }
    }
    
    if(temp->next==NULL && temp->val>=10){
        struct ListNode*new=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val=temp->val-10;
        new->val=1;
        temp->next=new;
    new->next=NULL;
    }
    temp=temp->next;
}
    return head;
}