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
12
13int countNodes(struct TreeNode* root){
14    if(root == NULL){
15        return 0;
16    }
17
18    return 1 + countNodes(root->left) + countNodes(root->right);
19}
20
21void fillArray(struct TreeNode* root, int* result, int* index){
22    if(root == NULL){
23        return;
24    }
25
26    
27    fillArray(root->left,result,index);
28    fillArray(root->right,result,index);
29
30    result[*index] = root->val;
31    (*index)++;
32}
33
34
35int* postorderTraversal(struct TreeNode* root, int* returnSize) {
36    *returnSize = countNodes(root);
37    int * result = malloc(*returnSize*sizeof(int));
38
39    int index = 0;
40
41    fillArray(root, result, &index);
42    
43    return result;
44}