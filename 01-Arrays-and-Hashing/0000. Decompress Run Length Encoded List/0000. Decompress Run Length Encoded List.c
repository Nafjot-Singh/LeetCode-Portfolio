1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
5    int total_size=0;
6    
7    for(int i=0; i<numsSize; i+=2){
8        total_size+=nums[i];
9    }
10
11    *returnSize = total_size;
12    int * result = malloc(total_size*sizeof(int));
13    int k=0;
14    
15    for(int i=0; i<numsSize; i+=2){
16        int freq = nums[i];
17        int val = nums[i + 1];
18
19        for(int j=0; j<freq; j++){
20            result[k++] = val;
21        }
22    }
23
24    return result;
25}