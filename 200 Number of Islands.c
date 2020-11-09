"""
Created on Mon Nov. 09 15:39 2020

@author: Chiwen Chen
"""

int numIslands(char** grid, int gridSize, int* gridColSize){
    int i,j;
    int num=0;
    for(i=0; i < gridSize;i++){
        for(j=0; j < gridColSize[i]; j++){
            if(grid[i][j]=='1'){
                visit(grid,i,j,gridSize,gridColSize);
                num=num+1;
            }
            
        }
        
    }
    return num;

}

void visit(char **grid, int i, int j, int gridSize, int *gridColSize)
{
    if (i < 0 || j < 0 || i >= gridSize)
        return;
    
    if (j >= gridColSize[i])
        return;
    
    if (grid[i][j] == '0')
        return;
    
    grid[i][j] = '0';
    
    visit(grid, i-1, j, gridSize, gridColSize);//<
    visit(grid, i+1, j, gridSize, gridColSize);//>
    visit(grid, i, j-1, gridSize, gridColSize);//up
    visit(grid, i, j+1, gridSize, gridColSize);//down
}
//Runtime: 12 ms, faster than 77.52% of C online submissions for Number of Islands.
//Memory Usage: 7.8 MB, less than 5.05% of C online submissions for Number of Islands.