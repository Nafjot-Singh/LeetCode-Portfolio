1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8
9
10struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
11
12    struct ListNode * start = list1;
13    for(int i=1; i<a; i++){
14        start=start->next;
15    }
16
17    struct ListNode * q = start->next;
18    for(int i=0; i<(b-a+1); i++){
19        q=q->next;
20    }
21
22    struct ListNode * end = list2;
23
24    while(end->next != NULL){
25
26        end = end->next;
27
28    }
29
30    start->next=list2;
31    end->next = q;
32
33    return list1;
34}