class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        depth = n // 2
        for i in range(depth):
            rlen, opp = n - 2 * i - 1, n - 1 - i
            for j in range(rlen):
                temp = matrix[i][i+j]
                matrix[i][i+j] = matrix[opp-j][i]
                matrix[opp-j][i] = matrix[opp][opp-j]
                matrix[opp][opp-j] = matrix[i+j][opp]
                matrix[i+j][opp] = temp
                
#                 Runtime: 36 ms, faster than 55.98% of Python3 online submissions for Rotate Image.
# Memory Usage: 14.3 MB, less than 30.16% of Python3 online submissions for Rotate Image.
