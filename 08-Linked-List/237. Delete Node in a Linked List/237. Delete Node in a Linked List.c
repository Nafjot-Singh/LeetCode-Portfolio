1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8
9void  deleteNode(struct ListNode* node) {
10    node->val = node->next->val;
11    node->next = node->next->next;
12}