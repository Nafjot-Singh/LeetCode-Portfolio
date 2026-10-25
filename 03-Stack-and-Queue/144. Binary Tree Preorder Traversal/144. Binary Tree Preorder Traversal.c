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
26    result[*index] = root->val;
27    (*index)++;
28    fillArray(root->left,result,index);
29    fillArray(root->right,result,index);
30}
31int* preorderTraversal(struct TreeNode* root, int* returnSize) {
32    
33    *returnSize = countNodes(root);
34    int * result = malloc(*returnSize*sizeof(int));
35
36    int index = 0;
37
38    fillArray(root, result, &index);
39    
40    return result;
41}