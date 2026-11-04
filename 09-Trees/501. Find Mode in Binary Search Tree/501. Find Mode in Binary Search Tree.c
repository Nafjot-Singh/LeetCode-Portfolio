1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9/**
10 * Note: The returned array must be malloced, assume caller calls free().
11 */
12void getModeCount(struct TreeNode* root, struct TreeNode** prev, int * curr_streak, int * max_streak,int * modeCount){
13    if(root == NULL){
14        return;
15    }
16
17    getModeCount(root->left, prev, curr_streak, max_streak, modeCount);
18
19    if(*prev != NULL && (*prev)->val == root->val){
20        (*curr_streak)++;
21    }
22    else{
23        *curr_streak = 1;
24    }
25
26    if(*curr_streak > *max_streak){
27        *max_streak = *curr_streak;
28        *modeCount = 1;
29    }
30    else if(*curr_streak == *max_streak){
31        (*modeCount)++;
32    }
33    
34    *prev = root;
35
36    getModeCount(root->right, prev, curr_streak, max_streak, modeCount);
37}
38
39void fillModeArray(struct TreeNode* root, struct TreeNode** prev, int * curr_streak, int * max_streak,int * modeCount, int * result, int * index){
40    if(root == NULL){
41        return;
42    }
43
44    fillModeArray(root->left, prev, curr_streak, max_streak, modeCount, result, index);
45
46    if((*prev) != NULL && (*prev)->val == root->val){
47        (*curr_streak)++;
48    }
49    else{
50        *curr_streak = 1;
51    }
52
53
54    if(*curr_streak == *max_streak){
55        result[*index] = root->val;
56        (*index)++;
57
58    }
59    
60    *prev = root;
61
62    fillModeArray(root->right, prev, curr_streak, max_streak, modeCount, result, index);
63
64}
65
66
67int* findMode(struct TreeNode* root, int* returnSize) {
68
69    struct TreeNode * prev = NULL;
70    int curr_streak = 0;
71    int max_streak = 0;
72    int modeCount = 0;
73
74    getModeCount(root, &prev, &curr_streak, &max_streak, &modeCount);
75
76    *returnSize = modeCount;
77    int * result = malloc(modeCount*sizeof(int));
78
79    prev = NULL;
80    curr_streak = 0;
81    int index = 0;
82
83    fillModeArray(root, &prev, &curr_streak, &max_streak, &modeCount, result, &index);
84
85    return result;
86}