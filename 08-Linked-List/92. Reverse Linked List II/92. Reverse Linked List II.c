1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8
9struct ListNode * reverse(struct ListNode * head,int n, struct ListNode ** join_node){
10    struct ListNode * prev = NULL;
11    struct ListNode * curr = head;
12    struct ListNode * next_node = NULL;
13
14    for(int i=0; i<n; i++){
15        next_node=curr->next;
16        curr->next = prev;
17        prev = curr;
18        curr=next_node;
19    }
20
21    *join_node = curr;
22
23    return prev;
24}
25
26struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
27    if(left==right || head->next == NULL) return head;
28    
29    struct ListNode dummy;
30    dummy.next=head;
31    struct ListNode * q = &dummy;
32
33    for(int i=1; i<left; i++){
34        q=q->next;
35    }
36
37    struct ListNode * p = q->next;
38    struct ListNode * reverse_end = p;
39    struct ListNode * join_node = NULL;
40    
41    q->next= reverse(p, (right-left)+1, &join_node);
42    
43    reverse_end->next = join_node;
44
45    return dummy.next;
46}