1void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
2    int * nums1_c = malloc(m*sizeof(int));
3
4    for(int i=0; i<m; i++){
5        nums1_c[i] = nums1[i];
6    }
7
8    int i=0;
9    int j=0;
10    int k=0;
11    
12    while(i<m && j<n){
13        if(nums1_c[i] < nums2[j]){
14            nums1[k++]  = nums1_c[i++];
15            
16        }
17        else{
18            nums1[k++]  = nums2[j++];
19        }
20    }
21
22    if(i<m){
23        while(i<m){
24            nums1[k++]  = nums1_c[i++];
25        }
26    }
27
28    if(j<nums2Size){
29        while(j<nums2Size){
30            nums1[k++]  = nums2[j++];
31        }
32    }
33    free(nums1_c);
34}