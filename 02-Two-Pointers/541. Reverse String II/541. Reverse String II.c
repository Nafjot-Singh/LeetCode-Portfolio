1
2char* reverseStr(char* s, int k) {
3    int size = strlen(s);
4    int i=0;
5
6    while(i<size){
7        int low = i;
8        int high;
9
10        if(i+k >= size){
11            high=size-1;
12        }
13        else{
14            high = i+k-1;
15        }
16
17        while(low<high){
18            char temp = s[low];
19            s[low] = s[high];
20            s[high] = temp;
21            low++;
22            high--;
23        }
24
25        i+= (2*k);
26    }
27
28    return s;
29}