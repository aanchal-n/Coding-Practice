#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    if (head==NULL || (head->next==NULL && n==1))
    {
        return NULL;
    }

    /* Finding the length of the list */
    int length=0;
    struct ListNode* temp=head;

    while(temp!=NULL)
    {
        temp = temp->next;
        length++;
    }
    int toRemove = length-n;
    
    if (toRemove==0)
    {
        head=head->next;
        return head;
    }

    //printf("%d",toRemove);

    temp = head;
    for (int i=0; i<toRemove-1;i++)
    {
        temp=temp->next;
    }

    temp->next = temp->next->next;
    return head; 
}
