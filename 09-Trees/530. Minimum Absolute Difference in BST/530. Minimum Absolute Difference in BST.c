1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9
10void inorder(struct TreeNode* root,int* min_diff, int* prev){
11    if(root == NULL){
12        return;
13    }
14
15    inorder(root->left, min_diff, prev);
16
17    if(*prev != -1){
18        int diff = root->val - (*prev);
19        if(diff <*min_diff){
20            *min_diff = diff;
21        }
22    }
23    
24    *prev = root->val;
25
26    inorder(root->right,min_diff, prev);
27}
28
29int getMinimumDifference(struct TreeNode* root) {
30    int min_diff = INT_MAX;
31    int prev = -1;
32    
33    inorder(root,&min_diff, &prev);
34
35    return min_diff;
36}