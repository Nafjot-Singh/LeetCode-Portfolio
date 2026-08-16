1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8
9
10struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
11
12    struct ListNode * node_before_a = list1;
13    for(int i=1; i<a; i++){
14        node_before_a=node_before_a->next;
15    }
16
17    struct ListNode * current_node = node_before_a->next;
18    for(int i=0; i < (b - a + 1); i++){
19        struct ListNode* temp = current_node;
20        current_node=current_node->next;
21        free(temp);
22    }
23
24    struct ListNode * list2_tail = list2;
25    while(list2_tail->next != NULL){
26        list2_tail = list2_tail->next;
27    }
28
29    node_before_a->next=list2;
30    list2_tail->next = current_node;
31
32    return list1;
33}