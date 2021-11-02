
#define OBSTACLE -1
#define SPACE 0
#define START 1
#define END 2
#define VISITED 3

int dfs(int **grid, int rowSize, int colSize, int rowIdx, int colIdx, int totalEmptySpaces){
    
    if((rowIdx < 0) || (rowIdx >= rowSize) || (colIdx < 0) || (colIdx >= colSize) || (grid[rowIdx][colIdx] == OBSTACLE)){
        return 0;
    }
    
    if(grid[rowIdx][colIdx] == END){
        return totalEmptySpaces == 0;
    }
    
    // block this path until we visit every node
    grid[rowIdx][colIdx] = OBSTACLE;
    
    int path = 0;
    
    path = dfs(grid, rowSize, colSize, rowIdx-1, colIdx, totalEmptySpaces-1) +
        dfs(grid, rowSize, colSize, rowIdx+1, colIdx, totalEmptySpaces-1) +
        dfs(grid, rowSize, colSize, rowIdx, colIdx-1, totalEmptySpaces-1) +
        dfs(grid, rowSize, colSize, rowIdx, colIdx+1, totalEmptySpaces-1);
    
    // restore the path again, for new iteration
    grid[rowIdx][colIdx] = SPACE;
    
    return path;
}

int uniquePathsIII(int** grid, int gridSize, int* gridColSize){

    int rowSize = gridSize, colSize = *gridColSize;
    int emptySpaces = 1, x = -1, y = -1;
    
    for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            if(grid[i][j] == SPACE){
                // count total number of empty spaces
                emptySpaces++;
            }
            else if(grid[i][j] == START){
                x = i;
                y = j;
            }
        }
    }
    return dfs(grid, rowSize, colSize, x, y, emptySpaces);  
}
