#include<stdio.h>
#include<stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* RemoveNextNode(struct ListNode* curNode)
{
    struct ListNode* temp=curNode;
    temp->next= curNode->next->next;
    return temp;
}

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* test = head;

    if (test == NULL)
    {
        printf("Works");
        return test;
    }

    while(test->next !=NULL)
    {
        if (test->val == test->next->val)
        {
            test = RemoveNextNode(test);
        }
        else
        {
            test = test->next;
        }

    }

    return head;
}
