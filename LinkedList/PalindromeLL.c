#include <stdlib.h>
#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* create_node(int val)
{
    struct ListNode* new_node = (struct ListNode*) malloc (sizeof(struct ListNode));
    new_node -> val = val;
    new_node -> next = NULL;
    return new_node;
}

bool isPalindrome(struct ListNode* head){

    struct ListNode* temp = head;
    struct ListNode* Reverse = NULL;
 
    while (temp != NULL)
    {
        struct ListNode* new_node = create_node(temp->val);
        new_node->next = Reverse;
        Reverse = new_node;
        temp = temp->next;
    }

    temp = head;

    while (temp!=NULL)
    {
        if (temp->val!=Reverse->val)
        {
            return false;
        }
        temp=temp->next;
        Reverse=Reverse->next;
    }

    return true;
 
}
