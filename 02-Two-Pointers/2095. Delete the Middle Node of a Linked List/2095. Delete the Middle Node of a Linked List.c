1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8struct ListNode* deleteMiddle(struct ListNode* head) {
9    if(head == NULL) return head;
10
11    if (head->next == NULL) {
12        free(head);
13        return NULL;
14    }
15
16    struct ListNode * prev;
17    struct ListNode * slow = head;
18    struct ListNode * fast = head;
19
20    while(fast && fast->next){
21        prev = slow;
22        slow = slow->next;
23        fast = fast->next->next;
24    }
25
26    prev->next = slow->next;
27    free(slow);
28    return head;
29}