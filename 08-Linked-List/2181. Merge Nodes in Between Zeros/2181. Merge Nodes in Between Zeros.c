1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8struct ListNode* mergeNodes(struct ListNode* head) {
9    struct ListNode * slow = head;
10
11    struct ListNode * fast = head->next;
12
13
14    while(fast != NULL){
15        int sum = 0;
16
17        while(fast->val != 0){
18            sum += fast->val;
19            struct ListNode * temp = fast;
20            fast = fast->next;
21            free(temp);
22        }
23
24        slow->val = sum;
25
26        if(fast->next == NULL){
27            slow->next = NULL;
28            free(fast);
29            break;
30        }
31        else{
32            slow->next = fast;
33            slow = fast;
34            fast = fast->next;
35        }
36    }
37
38    return head;
39}