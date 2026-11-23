1bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
2    int rows = matrixSize;
3    int cols = matrixColSize[0];
4    int low = 0;
5    int high = (rows*cols) - 1;
6    
7    while(low<=high){
8        int mid = (low+high)/2;
9
10        int val = matrix[mid/cols][mid%cols];
11
12        if(val == target){
13            return true;
14        }
15        else if(val>target){
16            high = mid-1;
17        }
18        else{
19            low = mid+1;
20        }
21    }
22    return false;
23}