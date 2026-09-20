1int countCommas(int n) {
2    int total_commas = 0;
3
4    if(n>=1000){
5        total_commas += n-999;
6    }
7
8    if(n>=1000000){
9        total_commas += n-99999;
10    }
11
12    return total_commas;
13}