1/**
2 * Return an array of arrays of size *returnSize.
3 * The sizes of the arrays are returned as *returnColumnSizes array.
4 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
5 */
6
7void backtrack(int* nums, int numsSize, int start_index, int * current_subset, int subset_size, int** result, int * returnSize, int * columnSizes){
8
9    result[*returnSize] = malloc(subset_size * sizeof(int));
10    for(int i=0; i<subset_size; i++){
11        result[*returnSize][i] = current_subset[i];
12    }
13
14    columnSizes[*returnSize] = subset_size;
15    (*returnSize)++;
16
17    for(int i=start_index; i<numsSize; i++){
18
19        current_subset[subset_size] = nums[i];
20
21        backtrack(nums, numsSize, i + 1, current_subset, subset_size + 1, result, returnSize, columnSizes);
22    }
23}
24
25
26int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
27    int total_size = 1 << numsSize;
28
29    int** result = malloc(total_size * sizeof(int*));
30    *returnColumnSizes = malloc(total_size * sizeof(int));
31    *returnSize = 0;
32
33    int* current_subset = malloc(numsSize * sizeof(int));
34
35    backtrack(nums, numsSize, 0, current_subset, 0, result, returnSize, *returnColumnSizes);
36
37    free(current_subset);
38
39    return result;
40}