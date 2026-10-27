1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9void inorder(struct TreeNode* root,int* min_diff, int* prev){
10    if(root == NULL){
11        return;
12    }
13
14    inorder(root->left, min_diff, prev);
15
16    if(*prev != -1){
17        int diff = root->val - (*prev);
18        if(diff <*min_diff){
19            *min_diff = diff;
20        }
21    }
22    
23    *prev = root->val;
24
25    inorder(root->right,min_diff, prev);
26}
27
28int minDiffInBST(struct TreeNode* root) {
29    int min_diff = INT_MAX;
30    int prev = -1;
31    
32    inorder(root,&min_diff, &prev);
33
34    return min_diff;
35}