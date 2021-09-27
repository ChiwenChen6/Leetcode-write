

int movesToChessboard(int** board, int boardSize, int* boardColSize){
    int rowSum = 0, colSum = 0, row = 0, col = 0;
    for (int i = 0; i < boardSize; ++i) 
        for (int j = 0; j < boardSize; ++j)
            if (board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) return -1;
    for (int i = 0; i < boardSize; ++i) 
    {
        rowSum += board[0][i];
        colSum += board[i][0];
        if((i % 2) == board[i][0]) row++;
        if((i % 2) == board[0][i]) col++;
    }
    if (boardSize / 2 > rowSum || rowSum > (boardSize + 1) / 2) return -1;
    if (boardSize / 2 > colSum || colSum > (boardSize + 1) / 2) return -1;
    if (boardSize % 2)
    {
        if (row % 2) row = boardSize - row;
        if (col % 2) col = boardSize - col;
    }
    else 
    {
        row = boardSize - row < row ? boardSize - row : row;
        col = boardSize - col < col ? boardSize - col : col;
    }
    return (row + col) / 2;

}
