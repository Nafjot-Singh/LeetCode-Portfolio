1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8struct ListNode * reverseList(struct ListNode* head){
9    struct ListNode * prev = NULL;
10    struct ListNode * curr = head;
11    struct ListNode * next_node = NULL;
12
13    while(curr!=NULL){
14        next_node = curr->next;
15        curr->next = prev;
16        prev = curr;
17        curr = next_node;
18    }
19
20    return prev;
21}
22
23int pairSum(struct ListNode* head) {
24    struct ListNode * slow = head;
25    struct ListNode * fast = head;
26
27    while(fast!=NULL){
28        slow=slow->next;
29        fast=fast->next->next;
30    }
31
32    struct ListNode* new_head = reverseList(slow);
33
34    int maxSum = 0;
35
36    while(new_head!=NULL){
37        if(head->val+new_head->val > maxSum){
38            maxSum = head->val+new_head->val;
39        }
40        head=head->next;
41        new_head=new_head->next;
42    }
43
44    return maxSum;
45}