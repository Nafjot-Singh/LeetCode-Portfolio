1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
5    int * result = malloc(numsSize*sizeof(int));
6    *returnSize = numsSize;
7
8    int total_sum=0;
9    for(int i=0; i<numsSize; i++){
10        total_sum+=nums[i];
11    }
12    
13    int left_sum = 0;
14    int right_sum = total_sum;
15
16
17    for(int i=0; i<numsSize; i++){
18
19        right_sum -= nums[i];
20
21        result[i] = abs(left_sum - right_sum);
22
23        left_sum += nums[i];
24    }
25
26    
27    return result;
28}