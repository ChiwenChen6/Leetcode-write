bool findWord(char** board, int boardSize, int boardColSize, char * word, int index, int row, int col){
    if (row < 0 || col < 0 || row >= boardSize || col >= boardColSize)
        return false;
    if (board[row][col] != word[index])
        return false;
    else{
        board[row][col] = '*';
    }
    if (word[index + 1] == '\0')
        return true;
    bool find = false;
    find = findWord(board, boardSize, boardColSize, word, index + 1, row - 1, col);
    if (find)
        return true;
    find = findWord(board, boardSize, boardColSize, word, index + 1, row + 1, col);
    if (find)
        return true;
    find = findWord(board, boardSize, boardColSize, word, index + 1, row, col - 1);
    if (find)
        return true;
    find = findWord(board, boardSize, boardColSize, word, index + 1, row, col + 1);
    if (find)
        return true;
    board[row][col] = word[index];
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardColSize[i]; j++){
            if (board[i][j] != word[0])
                continue;
            if (findWord(board, boardSize, boardColSize[0], word, 0, i, j)){
                return true;
            }
        }
    }
    return false;
}

Runtime: 108 ms, faster than 86.42% of C online submissions for Word Search.
Memory Usage: 5.7 MB, less than 47.53% of C online submissions for Word Search.
