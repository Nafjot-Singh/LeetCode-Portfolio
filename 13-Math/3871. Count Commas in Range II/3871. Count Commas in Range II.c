1long long countCommas(long long n) {
2    long long total_commas = 0;
3    long long threshold = 1000;
4
5    while(n>=threshold){
6        total_commas += n- threshold + 1;
7
8        if(threshold > n/1000){
9            break;
10        }
11
12        threshold *= 1000;
13    }
14
15    return total_commas;
16}