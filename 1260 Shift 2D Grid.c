/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    int m = gridSize;
    int n = gridColSize[0];
    
    k = (m*n) - k % (m*n);
    
    *returnSize = m;
    int** res = malloc(m * sizeof(int*));
    *returnColumnSizes = malloc(m * sizeof(int));
    
    for(int i=0; i<m; i++) {
        res[i] = malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        
        for(int j=0; j<n; j++) {
            int row = ((i*n+j+k)/n)%m;
            int column = (i*n+j+k)%n;
            res[i][j] = grid[row][column];
        }
    }
    
    return res;
}
