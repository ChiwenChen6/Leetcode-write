class Solution:
    def sum9x9(self,m,n):
        return sum(self.tmp[m][n:n+3]) + sum(self.tmp[m+1][n:n+3]) + sum(self.tmp[m+2][n:n+3])
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        b_m,b_n,self.tmp = len(board),len(board[0]),[]
        for i in range(b_m + 2):
            if i==0 or i == b_m + 1:
                self.tmp.append([0]*(b_n+2))
            else : 
                self.tmp.append([0] + board[i-1] + [0])
        for i in range(b_m):
            for j in range(b_n):
                if board[i][j] != 0: 
                    board[i][j] = [0,1][self.sum9x9(i,j) == 3 or self.sum9x9(i,j) ==4]
                else : 
                    board[i][j] = [0,1][self.sum9x9(i,j) == 3]   
