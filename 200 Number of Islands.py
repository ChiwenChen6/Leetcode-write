"""
Created on Mon Nov. 09 16:28 2020

@author: Chiwen Chen
"""

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if len(grid) == 0: return 0
    
        row , col  = len(grid), len(grid[0])
        ans = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == '1':
                    q = [(i, j)]
                    while q:
                        x, y = q.pop()
                        """point out"""
                        grid[x][y] = '2'
                        """"search near"""
                        for sx, sy in (0, 1), (0, -1), (1, 0), (-1, 0):
                            new_x, new_y = x+sx, y+sy
                            if 0 <= new_x < row and 0 <= new_y < col and grid[new_x][new_y] == '1':
                                q.append((new_x, new_y))
                    ans += 1            
        return ans
    """
    Runtime: 128 ms, faster than 92.31% of Python3 online submissions for Number of Islands.
    Memory Usage: 15 MB, less than 5.62% of Python3 online submissions for Number of Islands.
    """