1int minOperations(int* nums, int numsSize, int k) {
2    int remainder_sum=0;
3    for(int i=0; i<numsSize; i++){
4        remainder_sum=(remainder_sum+nums[i])%k;
5    }
6    
7    return remainder_sum;
8}