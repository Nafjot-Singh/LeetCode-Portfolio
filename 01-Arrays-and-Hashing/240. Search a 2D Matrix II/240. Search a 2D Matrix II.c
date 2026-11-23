1
2
3bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
4    if (matrixSize == 0 || matrixColSize[0] == 0) {
5        return false;
6    }
7
8    
9    int row = 0;
10    int col = matrixColSize[0]-1;
11
12    while(row < matrixSize && col >=0){
13        if(matrix[row][col] == target){
14            return true;
15        }
16        else if(matrix[row][col] > target){
17            col--;
18        }
19        else{
20            row++;
21        }
22    }
23    return false;
24}