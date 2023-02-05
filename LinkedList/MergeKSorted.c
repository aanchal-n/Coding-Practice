struct ListNode* SortedMerge(struct ListNode* a,struct ListNode* b)
{
    struct ListNode* result = NULL;
 
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->val <= b->val) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
 
    return result;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){

    int last = listsSize;

    while (last != 0) {
        int i = 0, j = last;
 
        while (i < j) {
            lists[i] = SortedMerge(lists[i], lists[j]);
            i++, j--;
            if (i >= j)
                last = j;
        }
    }
 
    return lists[0];
}
