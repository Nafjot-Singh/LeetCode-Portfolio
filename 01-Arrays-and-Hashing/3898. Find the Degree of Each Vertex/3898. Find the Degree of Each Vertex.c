1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* findDegrees(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
5    int * ans = calloc(matrixSize , sizeof(int));
6    *returnSize = matrixSize;
7    for(int i=0; i<matrixSize; i++){
8        for(int j=0; j<matrixSize; j++){
9            ans[i] += matrix[i][j];
10        }
11    }
12
13    return ans;
14}