class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        row,col=len(matrix),len(matrix[0])
        prev=[0]*(1+col)
        maximum=0
        for i in range(row):
            curr=[0]*(1+col)
            for j in range(1,1+col):
                if matrix[i][j-1]=="1":
                    curr[j]=1+min(curr[j-1],prev[j],prev[j-1])
            prev=curr        
            maximum=max(maximum,max(curr))      
        return maximum**2
