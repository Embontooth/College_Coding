struct ListNode{
    int val;
    struct ListNode next;
};
void deleteNode(struct ListNode* node) {
    int temp = node->val;
    node->val=node->next->val;
    node->next->val=temp;
    node->next=node->next->next;
}