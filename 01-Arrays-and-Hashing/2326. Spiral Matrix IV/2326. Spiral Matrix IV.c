1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     struct ListNode *next;
6 * };
7 */
8
9/**
10 * Return an array of arrays of size *returnSize.
11 * The sizes of the arrays are returned as *returnColumnSizes array.
12 * Note: Both returned array and *columnSizes array must be malloced, assume
13 * caller calls free().
14 */
15struct ListNode* go_right(struct ListNode* head, int** arr, int* row_low,
16                          int* row_high, int* col_low, int* col_high, int* row,
17                          int* col) {
18    struct ListNode* tail = head;
19    for (int j = *col_low; j < *col_high; j++) {
20        if (tail != NULL) {
21            arr[*row_low][j] = tail->val;
22            tail = tail->next;
23        } else {
24            arr[*row_low][j] = -1;
25        }
26    }
27    (*row_low)++;
28    *row = *row_low;
29    *col = *col_high - 1;
30
31    return tail;
32}
33
34struct ListNode* go_down(struct ListNode* head, int** arr, int* row_low,
35                         int* row_high, int* col_low, int* col_high, int* row,
36                         int* col) {
37    struct ListNode* tail = head;
38    for (int i = *row_low; i < *row_high; i++) {
39        if (tail != NULL) {
40            arr[i][*col_high - 1] = tail->val;
41            tail = tail->next;
42        } else {
43            arr[i][*col_high - 1] = -1;
44        }
45    }
46    (*col_high)--;
47    *row = *row_high - 1;
48    *col = *col_high - 1;
49
50    return tail;
51}
52
53struct ListNode* go_left(struct ListNode* head, int** arr, int* row_low,
54                         int* row_high, int* col_low, int* col_high, int* row,
55                         int* col) {
56    struct ListNode* tail = head;
57    for (int j = *col_high - 1; j >= *col_low; j--) {
58        if (tail != NULL) {
59            arr[*row_high - 1][j] = tail->val;
60            tail = tail->next;
61        } else {
62            arr[*row_high - 1][j] = -1;
63        }
64    }
65    (*row_high)--;
66    *row = *row_high - 1;
67    *col = *col_low;
68
69    return tail;
70}
71
72struct ListNode* go_up(struct ListNode* head, int** arr, int* row_low,
73                       int* row_high, int* col_low, int* col_high, int* row,
74                       int* col) {
75    struct ListNode* tail = head;
76    for (int i = *row_high - 1; i >= *row_low; i--) {
77        if (tail != NULL) {
78            arr[i][*col_low] = tail->val;
79            tail = tail->next;
80        } else {
81            arr[i][*col_low] = -1;
82        }
83    }
84    (*col_low)++;
85    *row = *row_low;
86    *col = *col_low;
87
88    return tail;
89}
90
91int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize,
92                   int** returnColumnSizes) {
93
94    *returnSize = m;
95
96    int* sizes = malloc(m * sizeof(int));
97    for (int i = 0; i < m; i++) {
98        sizes[i] = n;
99    }
100    *returnColumnSizes = sizes;
101
102    int row_low = 0;
103    int row_high = m;
104    int col_low = 0;
105    int col_high = n;
106
107    int row = 0;
108    int col = 0;
109
110    struct ListNode* ptr = head;
111    int** result = malloc(m * sizeof(int*));
112    for (int i = 0; i < m; i++) {
113        result[i] = malloc(n * sizeof(int));
114    }
115
116    while (row_low < row_high && col_low < col_high) {
117        
118        ptr = go_right(ptr, result, &row_low, &row_high, &col_low, &col_high, &row, &col);
119        
120
121        if (row_low < row_high && col_low < col_high) {
122            ptr = go_down(ptr, result, &row_low, &row_high, &col_low, &col_high,
123                          &row, &col);
124        }
125
126        if (row_low < row_high && col_low < col_high) {
127            ptr = go_left(ptr, result, &row_low, &row_high, &col_low, &col_high,
128                          &row, &col);
129        }
130
131        if (row_low < row_high && col_low < col_high) {
132            ptr = go_up(ptr, result, &row_low, &row_high, &col_low, &col_high,
133                        &row, &col);
134        }
135    }
136
137    return result;
138}
139