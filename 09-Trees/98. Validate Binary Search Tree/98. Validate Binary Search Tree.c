1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9bool isBSTUtil(struct TreeNode* root, long min_val, long max_val){
10    if(root == NULL){
11        return true;
12    }
13
14    if(root->val <= min_val || root->val >= max_val){
15        return false;
16    }
17
18    return isBSTUtil(root->left, min_val,root->val) && isBSTUtil(root->right, root->val, max_val);
19}
20bool isValidBST(struct TreeNode* root) {
21    return isBSTUtil(root, LONG_MIN, LONG_MAX);
22}