1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* getConcatenation(int* nums, int numsSize, int* returnSize) {
5    int * ans = malloc(2*numsSize*sizeof(int));
6
7    for(int i=0; i<numsSize; i++){
8        int temp = nums[i];
9        ans[i] = temp;
10        ans[i+numsSize] = temp;
11    }
12
13    *returnSize = 2*numsSize;
14    return ans;
15}