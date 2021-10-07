class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board or not word: return False
        for m in range(len(board)):
            for n in range(len(board[0])):
                if self.dfs(m,n,word,board):
                    return True
        return False
        
    def dfs(self,i,j,word,board):
        if i<0 or j<0 or i>=len(board) or j>=len(board[0]):
            return False
            
        if word == board[i][j]:
            return True
        elif len(word) == 1:
            return False
            
        if board[i][j] != word[0]:
            return False
        
        elif board[i][j] == word[0]:
            tmp = board[i][j]
            board[i][j] = '#'
            res = self.dfs(i-1,j, word[1:],board) or self.dfs(i,j-1,word[1:],board) or self.dfs(i+1,j,word[1:],board) or self.dfs(i,j+1,word[1:],board)
        
            board[i][j] = tmp
            return res
