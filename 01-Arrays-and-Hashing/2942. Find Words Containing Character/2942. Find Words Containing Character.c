1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
5    int * result = malloc(wordsSize*sizeof(int));
6    int size =0;
7
8    for(int i=0; i<wordsSize; i++){
9        int j=0;
10        while(words[i][j]!='\0'){
11            if(words[i][j] == x){
12                result[size++] = i;
13                break;
14            }
15            j++;
16        }
17    }
18
19    *returnSize = size;
20
21    return result;
22}