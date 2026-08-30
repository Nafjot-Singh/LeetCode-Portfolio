1int countNegatives(int** grid, int gridSize, int* gridColSize) {
2    int count=0;
3    int i=0;
4    int j=gridColSize[0]-1;
5
6    while(i<gridSize && j>=0){
7        if(grid[i][j] < 0){
8            count += gridSize-i;
9            j--;
10        }
11        else{
12            i++;
13        }
14    }
15
16    return count;
17}