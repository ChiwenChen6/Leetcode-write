class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        
        if matrix and matrix[0]:
            self.summ = [[0]*(len(matrix[0])+1) for _ in range(len(matrix)+1)]
            for i in range(1, len(matrix)+1):
                for j in range(1, len(matrix[0])+1):
                    self.summ[i][j] = self.summ[i-1][j]+self.summ[i][j-1]-self.summ[i-1][j-1]+matrix[i-1][j-1]
                

    def sumRegion(self, row1, col1, row2, col2):

        return self.summ[row2+1][col2+1] - self.summ[row2+1][col1] - self.summ[row1][col2+1] + self.summ[row1][col1]

# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
