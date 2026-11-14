1int mySqrt(int x) {
2    int count = 0;
3    int i = 1;
4    while(i<= x){
5        count++;
6        x = x - i;
7        i+=2;
8    }
9
10    return count;
11}