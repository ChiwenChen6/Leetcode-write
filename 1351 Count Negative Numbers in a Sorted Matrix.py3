class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        count = 0
        col  = 0

        while rows > 0 and col < cols:
            if grid[rows-1][col] < 0:
                count += cols - col
                rows -= 1
            else:
                col += 1

        return count
