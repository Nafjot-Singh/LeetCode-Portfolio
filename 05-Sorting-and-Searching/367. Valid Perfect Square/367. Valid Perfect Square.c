1bool isPerfectSquare(int num) {
2    if(num == 0 || num == 1){
3        return true;
4    }
5
6    int low = 1;
7    int high = num;
8    
9
10    while(low<=high){
11        int mid = (high-low)/2 + low;;
12        long squared = (long)mid*mid;
13
14        if(squared == num){
15            return true;
16        }
17        else if(mid <= num/mid){
18            low = mid+1;
19        }
20        else{
21            high = mid-1;
22        }
23    }
24
25    return false;
26}