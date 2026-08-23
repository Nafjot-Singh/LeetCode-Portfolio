1void rotate(int** matrix, int matrixSize, int* matrixColSize) {
2    for (int i = 0; i < matrixSize; i++) {
3        for (int j = i; j < matrixSize; j++) {
4            int temp = matrix[j][i];
5            matrix[j][i] = matrix[i][j];
6            matrix[i][j] = temp;
7        }
8    }
9    
10    for (int i = 0; i < matrixSize; i++) {
11        int low=0;
12        int high=matrixColSize[i]-1;
13        while(low<high){
14            int temp = matrix[i][high];
15            matrix[i][high] = matrix[i][low];
16            matrix[i][low] = temp;
17            low++;
18            high--;
19        }
20    }
21}