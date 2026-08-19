1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* concatWithReverse(int* nums, int numsSize, int* returnSize) {
5    
6    int * result = malloc(2*numsSize*sizeof(int));
7    *returnSize = 2*numsSize;
8    int k=0;
9
10    for(int i=0; i<numsSize; i++){
11        result[k++]=nums[i];
12    }
13
14    for(int i=numsSize-1; i>=0; i--){
15        result[k++]=nums[i];
16    }
17
18    return result;
19}