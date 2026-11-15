1bool isPerfectSquare(int num) {
2    if(num == 0 || num == 1){
3        return true;
4    }
5
6    int low = 1;
7    int high = num;
8    int result = 0;
9
10    while(low<=high){
11        int mid = (high-low)/2 + low;;
12
13        if(mid <= num/mid){
14            result = mid;
15            low = mid+1;
16        }
17        else{
18            high = mid-1;
19        }
20    }
21
22    if(result*result == num){
23        return true;
24    }
25    return false;
26}