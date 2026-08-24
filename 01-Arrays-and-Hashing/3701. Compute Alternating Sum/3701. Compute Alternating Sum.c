1int alternatingSum(int* nums, int numsSize) {
2    int sum =0;
3
4    for(int i=0; i<numsSize; i++){
5        if(i%2==0){
6            sum+=nums[i];
7        }
8        else{
9            sum-=nums[i];
10        }
11    }
12
13    return sum; 
14
15}