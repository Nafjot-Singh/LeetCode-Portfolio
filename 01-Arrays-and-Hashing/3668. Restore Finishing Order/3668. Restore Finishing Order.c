1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* recoverOrder(int* order, int orderSize, int* friends, int friendsSize, int* returnSize) {
5    *returnSize = friendsSize;
6    int * result = malloc(friendsSize*sizeof(int));
7    int k=0;
8
9    for(int i=0; i<orderSize; i++){
10        for(int j=0; j<friendsSize; j++){
11            if(order[i] == friends[j]){
12                result[k++] = friends[j];
13            }
14        }
15    }
16
17    return result;
18}