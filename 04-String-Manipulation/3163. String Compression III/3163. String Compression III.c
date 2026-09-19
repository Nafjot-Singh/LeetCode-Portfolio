1char* compressedString(char* word) {
2    int size = strlen(word);
3    int read=0;
4    int write=0;
5    char * comp = malloc((2*size+1)*sizeof(char));
6
7    while(read <size){
8        int current_char = word[read];
9        int count=0;
10
11        while(read<size && word[read] == current_char && count<9){
12            read++;
13            count++; 
14        }
15
16        comp[write++] = count + '0';
17        comp[write++]=current_char;
18    }
19
20    comp[write] = '\0';
21
22    return comp;
23}