/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void printList(struct ListNode* head)
{
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

struct ListNode* reverse(struct ListNode* curHead)
{
    // Reverse only tempHead 
    struct ListNode* prev = NULL;
    struct ListNode* current = curHead;
    struct ListNode* next =NULL;

    while (current!=NULL)
    {
        next = current->next;
        current ->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

int Length(struct ListNode* head)
{
    struct ListNode* curTemp = head;
    int len = 0;
    while(curTemp!=NULL)
    {
        curTemp = curTemp->next;
        len++;
    }
    return len;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* tempHead  = head;
    struct ListNode* restOfTheList = head;

    if (right == Length(head) && left==1)
    {
        return reverse(head);
    }
    

    int i=0;
    while (i<left-1)
    {
        tempHead = tempHead->next;
        i++;
    }

    int j=0;
    while(j<right)
    {
        restOfTheList = restOfTheList->next;
        j++;
    }


    struct ListNode* temp = tempHead;
    int iterations = right - left; //3
    while(iterations!=0)
    {
        temp =temp->next; 
        iterations--; 
    }
    temp->next = NULL; 

    tempHead = reverse(tempHead);


    struct ListNode* finalList = head;
    struct ListNode* cur = finalList;
    int k = 0;
    if (left==1)
    {
        finalList = tempHead;
    }
    else if (left == 2)
    {
        cur->next = tempHead;
    }
    else
    {
        while (k<left-2)
        {
            cur = cur->next;
            k++;
        }
        cur->next = tempHead;
    }

    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur -> next = restOfTheList;
    
    return finalList;
}
