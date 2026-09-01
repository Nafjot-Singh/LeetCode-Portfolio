1bool areSame(int arr1[], int arr2[]){
2    for(int i=0; i<26; i++){
3        if(arr1[i] != arr2[i]){
4            return false;
5        }
6    }
7
8    return true;
9}
10
11bool checkInclusion(char* s1, char* s2) {
12    int size1 = strlen(s1);
13    int size2 = strlen(s2);
14
15    if(size1>size2) return false;
16
17    int hash1[26] = {0};
18    for(int i=0; i<size1 ; i++){
19        hash1[s1[i]-'a']++;
20    }
21
22    int hash2[26]={0};
23
24    for(int i=0; i<size1; i++){
25        hash2[s2[i]-'a']++;
26    }
27    
28    if(areSame(hash1, hash2)){
29        return true;
30    }
31
32    for(int end=size1; end<size2; end++){
33        int start = end-size1;
34
35        hash2[s2[end] - 'a']++;
36        hash2[s2[start] - 'a']--;
37
38        if(areSame(hash1, hash2)){
39            return true;
40        }
41    }
42    
43    return false;
44}