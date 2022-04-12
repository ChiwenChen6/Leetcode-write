class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        
        if (k := k%(m*n)) == 0:
            return grid
          
        count = i = 0
        while count < m*n:
            r, c = divmod(i, n)
            curr, j = grid[r][c], (i+k)%(m*n) 
            
            while True:
                r, c = divmod(j, n)
                grid[r][c], curr = curr, grid[r][c] 
                count += 1 
                
                if j == i: 
                    break
                j = (j+k)%(m*n)
            i += 1  
        return grid
