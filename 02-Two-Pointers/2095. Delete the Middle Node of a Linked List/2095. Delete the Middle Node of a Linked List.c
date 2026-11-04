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
16    struct ListNode * slow = head;
17    struct ListNode * fast = head->next->next;
18
19    while(fast && fast->next){
20        slow = slow->next;
21        fast = fast->next->next;
22    }
23
24    struct ListNode* temp = slow->next;
25    slow->next = slow->next->next;
26    free(temp);
27    return head;
28}