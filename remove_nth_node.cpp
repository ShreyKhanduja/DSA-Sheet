

ListNode* removeNthFromEnd(ListNode *head, int n) {
    ListNode *slow = head;
    ListNode *fast = head;
    // move fast pointer by n steps
    for(int i = 0; i < n; i++)
        fast = fast->next;
    // edge cases: head node is to be deleted
    if(!fast)
        return head->next;
    
    // while fast reaches the last node
    while(fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    // delete slow->next node
    slow->next = slow->next->next;
    return head;
}

