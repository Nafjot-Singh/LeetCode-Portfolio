1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9
10// struct TreeNode * findMin(struct TreeNode * root){
11//     if(root->left == NULL || root == NULL){
12//         return root;
13//     }
14    
15//     return findMin(root->left);
16// }
17
18struct TreeNode* deleteNode(struct TreeNode* root, int key) {
19    if (root == NULL){
20        return NULL;
21    }
22
23    if(key < root->val){
24        root->left = deleteNode(root->left, key);
25    }
26    else if (key > root->val){
27        root->right = deleteNode(root->right, key);
28    }
29    else{
30
31        if(root->left == NULL){
32            struct TreeNode * temp = root->right;
33            free(root);
34            return temp;
35        }
36
37        if(root->right == NULL){
38            struct TreeNode * temp = root->left;
39            free(root);
40            return temp;
41        }
42
43        struct TreeNode * successor = root->right;
44        while(successor->left != NULL){
45            successor=successor->left;
46        }
47        root->val = successor->val;
48        root->right = deleteNode(root->right, successor->val);
49    }
50
51    return root;
52}