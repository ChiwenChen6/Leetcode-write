

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int perimeter = 0;    
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < *gridColSize; j++)
        {
            if (grid[i][j])
            {
                perimeter += 4;
                
                if (i > 0)
                    perimeter -= grid[i - 1][j];
                if (i < gridSize - 1)
                    perimeter -= grid[i + 1][j]; 
                if (j > 0)
                    perimeter -= grid[i][j - 1];
                if (j < *gridColSize - 1)
                    perimeter -= grid[i][j + 1];
            }
        }
    }
    return perimeter;
}
