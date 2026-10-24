1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9struct TreeNode* searchBST(struct TreeNode* root, int val) {
10    if(root == NULL){
11        return NULL;
12    }
13
14    if(val < root->val){
15        return searchBST(root->left, val);
16    }
17
18    if(val> root->val){
19        return searchBST(root->right, val);
20    }
21
22    return root;
23}