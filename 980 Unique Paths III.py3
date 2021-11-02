class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        m, n = len(grid), len(grid[0])
        non_empty_count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] != -1:
                    non_empty_count += 1
                if grid[i][j] == 1:
                    start_i, start_j = i, j
                    
        def backtrack(i, j, remain):
            if i < 0 or i == m or j < 0 or j == n or grid[i][j] == -1:
                return 0
            if grid[i][j] == 2:
                return remain == 1
            res = 0
            grid[i][j] = -1
            for x, y in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]:
                res += backtrack(x, y, remain-1)
            grid[i][j] = 0
            return res

        return backtrack(start_i, start_j, non_empty_count)
