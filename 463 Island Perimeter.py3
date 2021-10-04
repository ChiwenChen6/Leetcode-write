class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        row, col = len(grid), len(grid[0])
        rs = 0
        for i in range(row):
            for j in range(col):
                if not grid[i][j]:
                    continue
                rs += 4
                # statistic the right and down sides
                if i < row - 1 and grid[i+1][j]:
                    rs -= 2
                if j < col - 1 and grid[i][j+1]:
                    rs -= 2
        return rs
