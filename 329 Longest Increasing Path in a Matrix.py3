class Solution:
    
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        
        def dfs(i, j, length):
            if( (i,j) in cache ):
                return cache[(i,j)]

            maxLength = 0

            for x,y in [(0,1),(1,0),(-1,0),(0,-1)]:
                if 0 <= (i + x) < m and 0 <= (j + y) < n and matrix[i + x][j+  y] > matrix[i][j]:
                    maxLength = max( maxLength, dfs( (i + x), (j + y), (length + 1)) )

            cache[(i,j)] = 1 + maxLength
            return 1 + maxLength      
        
        if not matrix: return 0
        m = len(matrix)
        n = len(matrix[0])
        cache = {}
        for i in range(m):
            for j in range(n):
                if( (i,j) not in cache ):
                    dfs( i, j, 1 )
        return max(cache.values())
             
# Status: Accepted
# Runtime: 488 ms
# Memory Usage: 18.8 MB
