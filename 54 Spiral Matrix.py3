class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        
		# iteration variable
        left, right = 0, len(matrix[0]) - 1
        up, bottom = 0, len(matrix) - 1
        
        direction = 0
        result = []
        
        while left <= right and up <= bottom:
            if direction % 4 == 0:
                for i in range(left, right + 1):
                    result.append(matrix[up][i])
                up += 1
            elif direction % 4 == 1:
                for i in range(up, bottom + 1):
                    result.append(matrix[i][right])
                right -= 1
            elif direction % 4 == 2:
                for i in reversed(range(left, right + 1)):
                    result.append(matrix[bottom][i])
                bottom -= 1
            else:
                for i in reversed(range(up, bottom + 1)):
                    result.append(matrix[i][left])
                left += 1
            direction += 1
        
        return result
