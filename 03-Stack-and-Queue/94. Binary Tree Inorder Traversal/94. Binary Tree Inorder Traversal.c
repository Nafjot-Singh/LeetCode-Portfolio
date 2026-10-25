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
12int countNodes(struct TreeNode* root){
13    if(root == NULL){
14        return 0;
15    }
16
17    return 1 + countNodes(root->left) + countNodes(root->right);
18}
19
20void fillArray(struct TreeNode* root, int* result, int* index){
21    if(root == NULL){
22        return;
23    }
24
25    fillArray(root->left,result,index);
26
27    result[*index] = root->val;
28    (*index)++;
29
30    fillArray(root->right,result,index);
31}
32
33int* inorderTraversal(struct TreeNode* root, int* returnSize) {
34    
35
36    *returnSize = countNodes(root);
37    int * result = malloc(*returnSize*sizeof(int));
38
39    int index = 0;
40
41    fillArray(root, result, &index);
42    
43    return result;
44}