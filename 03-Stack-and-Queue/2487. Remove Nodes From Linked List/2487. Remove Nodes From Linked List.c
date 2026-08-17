1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8
9struct ListNode * reverseList(struct ListNode * head){
10    struct ListNode* prev = NULL;
11    struct ListNode* curr = head;
12    struct ListNode* next_node = NULL;
13
14    while(curr!=NULL){
15        next_node=curr->next;
16        curr->next=prev;
17        prev=curr;
18        curr=next_node;
19    }
20
21    return prev;
22}
23struct ListNode* removeNodes(struct ListNode* head) {
24   if(head == NULL) return head;
25
26   head = reverseList(head);
27
28   struct ListNode * curr = head;
29   int max_node = curr->val;
30
31   while(curr!=NULL && curr->next!=NULL){
32    if(curr->next->val < max_node){
33        struct ListNode * temp = curr->next;   
34        curr->next = curr->next->next;
35        free(temp);
36    }
37    else{
38        curr=curr->next;
39        max_node= curr->val;
40    }
41   }
42
43   return reverseList(head);
44}