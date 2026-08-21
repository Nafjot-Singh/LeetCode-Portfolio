1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* buildArray(int* nums, int numsSize, int* returnSize) {
5    *returnSize  = numsSize;
6    int * result = malloc(numsSize * sizeof(int));
7
8    for(int i=0; i<numsSize; i++){
9        result[i] = nums[nums[i]];
10    }
11
12    return result;
13}