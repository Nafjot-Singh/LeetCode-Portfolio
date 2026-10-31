1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9struct TreeNode * findMin(struct TreeNode * root){
10    if(root->left == NULL || root == NULL){
11        return root;
12    }
13    
14    return findMin(root->left);
15}
16struct TreeNode* deleteNode(struct TreeNode* root, int key) {
17    if (root == NULL){
18        return NULL;
19    }
20
21    if(key < root->val){
22        root->left = deleteNode(root->left, key);
23    }
24    else if (key > root->val){
25        root->right = deleteNode(root->right, key);
26    }
27    else{
28
29        if(root->left == NULL){
30            struct TreeNode * temp = root->right;
31            free(root);
32            return temp;
33        }
34
35        if(root->right == NULL){
36            struct TreeNode * temp = root->left;
37            free(root);
38            return temp;
39        }
40
41        struct TreeNode * successor = findMin(root->right);
42        root->val = successor->val;
43        root->right = deleteNode(root->right, successor->val);
44    }
45
46    return root;
47}