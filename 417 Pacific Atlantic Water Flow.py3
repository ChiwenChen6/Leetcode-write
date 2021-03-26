class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:

            if not matrix or not matrix[0]:
                return []
            
            m = len(matrix)
            n = len(matrix[0])
            p1_visited = set()
            p2_visited = set()
            
            directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]
            
            def dfs(visited, x, y):
                visited.add((x, y))
                for dx, dy in directions:
                    new_x, new_y = x + dx, y + dy
                    if 0 <= new_x < m and 0 <= new_y < n and (new_x, new_y) not in visited and matrix[x][y] <= matrix[new_x][new_y] :
                        dfs(visited, new_x, new_y)

            #left border and right border
            for i in range(m):
                dfs(p1_visited, i,0)
                dfs(p2_visited, i,n-1)

            # up border and bottom border
            for j in range(n):
                dfs(p1_visited, 0, j)
                dfs(p2_visited, m-1, j)

            return list(p1_visited.intersection(p2_visited))
