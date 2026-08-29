1/**
2 * Note: The returned array must be malloced, assume caller calls free().
3 */
4int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
5    int * result = malloc(wordsSize*sizeof(int));
6    int size =0;
7
8    for(int i=0; i<wordsSize; i++){
9        if(strchr(words[i], x) != NULL){
10            result[size++] = i;
11        }
12    }
13
14    *returnSize = size;
15
16    return result;
17}