1int maxAbsValExpr(int* arr1, int arr1Size, int* arr2, int arr2Size) {
2    int max_result = 0;
3
4    int sign1[] = {1,1,-1,-1};
5    int sign2[] = {1,-1,1,-1};
6
7    for(int k=0; k<4; k++){
8        int current_max = INT_MIN;
9        int current_min = INT_MAX;
10
11        for(int i=0; i<arr1Size; i++){
12            int val =  (sign1[k]*arr1[i]) + (sign2[k]*arr2[i]) + i;
13
14            if (val > current_max) current_max = val;
15            if (val < current_min) current_min = val;
16        }
17
18        int diff = current_max - current_min;
19
20        if(diff> max_result) max_result = diff;
21    }
22
23    return max_result;
24}