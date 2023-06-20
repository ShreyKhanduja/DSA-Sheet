
void deleteNode(ListNode *node) {
    // copy the value
    node->val = node->next->val;
    // delete the next node
    node->next = node->next->next;
}