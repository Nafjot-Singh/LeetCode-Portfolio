1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
9    struct ListNode dummy;
10    dummy.next = head;
11    
12    struct ListNode * slow = &dummy;
13    struct ListNode * fast = &dummy;
14
15    for(int i=0; i<n; i++){
16        fast=fast->next;
17    }
18
19    while(fast->next != NULL){
20        fast=fast->next;
21        slow=slow->next;
22    }
23    struct ListNode * node_before = slow->next;
24    slow->next = slow->next->next;
25    free(node_before);
26
27    return dummy.next;
28}