1/**
2 * Return an array of arrays of size *returnSize.
3 * The sizes of the arrays are returned as *returnColumnSizes array.
4 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
5 */
6int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
7
8    int rows = matrixSize;
9    int cols = matrixColSize[0];
10
11    *returnSize = cols;
12
13    int ** result = malloc(cols *sizeof(int*));
14    
15
16    int * returnSizes = malloc(cols *sizeof(int));
17    *returnColumnSizes = returnSizes;
18
19    for(int i=0; i<cols; i++){
20        result[i] = malloc(rows * sizeof(int));
21        returnSizes[i] = rows;
22    }
23
24
25    for(int i=0; i<rows; i++){
26        for(int j=0; j<cols; j++){
27            result[j][i] = matrix[i][j];
28        }
29    }
30
31    return result;
32}