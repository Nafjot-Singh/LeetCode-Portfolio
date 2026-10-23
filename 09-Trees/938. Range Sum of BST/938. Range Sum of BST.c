1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9
10int rangeSumBST(struct TreeNode* root, int low, int high) {
11    
12    if(root==NULL){
13        return 0;
14    }
15
16    if(root->val<low){
17        return rangeSumBST(root->right, low, high);
18    }
19
20    if(root->val > high){
21        return rangeSumBST(root->left, low, high);
22    }
23    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low,high);
24}