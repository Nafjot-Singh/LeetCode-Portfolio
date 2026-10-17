1bool uniformArray(int* nums1, int nums1Size) {
2    int min_val = nums1[0];
3    bool has_odd = false;
4
5    for(int i=0; i<nums1Size; i++){
6        if(nums1[i]<min_val){
7            min_val = nums1[i];
8        }
9        if(nums1[i]%2 != 0){
10            has_odd = true;
11        }
12    }
13
14    if(min_val%2 != 0){
15        return true;
16    }
17
18    if(!has_odd){
19        return true;
20    }
21
22    return false;
23}