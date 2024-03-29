
ListNode* addTwoNumbers(Listnode* l1, ListNode *l2) {
    ListNode head;
    ListNode *curr = &head;
    int carry = 0;

    while(l1 || l2 || carry) {
        if(l1) {
            carry += l1->val;
            l1 = l1->next;
        }
        if(l2) {
            carry += l2->val;
            l2 = l2->next;
        }
        // create new node
        curr->next = new ListNode(carry % 10);
        carry /= 10;
        // move curr to the last node (new node added)
        curr = curr->next;
    }
    return head.next;
}