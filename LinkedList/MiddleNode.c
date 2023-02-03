/**
 * Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
};
 */



struct ListNode* middleNode(struct ListNode* head){

    struct ListNode* temp = head;
    int length=0;

    while (temp!= NULL)
    {
        length++;
        temp=temp->next;
    }

    int middle = length/2 + 1;

    struct ListNode* test = head;
    for (int i=0; i < middle-1; i++)
    {
        test=test->next;
    }
    return test;
}
