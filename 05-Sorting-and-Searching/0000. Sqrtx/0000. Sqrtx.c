1int mySqrt(int x) {
2    if(x == 0 || x == 1){
3        return x;
4    }
5
6    int low = 1;
7    int high = x;
8    int result = 0;
9
10    while(low<=high){
11        int mid = (high-low)/2 + low;;
12
13        if(mid <= x/mid){
14            result = mid;
15            low = mid+1;
16        }
17        else{
18            high = mid-1;
19        }
20    }
21
22    return result;
23}