1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8
9
10struct ListNode * reverse(struct ListNode * head){
11    struct ListNode * prev = NULL;
12    struct ListNode * curr = head;
13    struct ListNode * next_node = NULL;
14
15    while(curr != NULL){
16        next_node = curr->next;
17        curr->next = prev;
18        prev = curr;
19        curr = next_node;
20    }
21
22    return prev;
23}
24
25void reorderList(struct ListNode* head) {
26    if (head == NULL || head->next == NULL) return;
27
28    
29    struct ListNode* slow = head;
30    struct ListNode* fast = head->next;
31    
32    
33    while (fast != NULL && fast->next != NULL) {
34        slow = slow->next;
35        fast = fast->next->next;
36    }
37    
38    struct ListNode* second_half = slow->next;
39    slow->next = NULL; 
40
41    
42    struct ListNode* p = head;
43    struct ListNode* q = reverse(second_half);
44    
45
46    while(q != NULL){
47        struct ListNode * p_next = p->next;
48        struct ListNode * q_next = q->next;
49
50        p->next = q;
51        q->next = p_next;
52
53        p = p_next;
54        q = q_next;        
55    }
56
57
58}