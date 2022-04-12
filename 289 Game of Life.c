const int dx[] = {0, 0, 1, 1, 1,-1,-1,-1};
const int dy[] = {1,-1, 0, 1,-1, 0, 1,-1};

void gameOfLife(int** board, int boardSize, int *boardColSize) {
        int row = boardSize, col = *boardColSize;

        for(int i =  0; i < row; i++){
            for(int j = 0; j < col; j++){
                int cnt = 0;
                for(int k = 0; k < 8; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if(x < 0 || y < 0 || x >= row || y >= col){
                        continue;
                    }
                    cnt += (board[x][y]&1);
                }
                if((board[i][j] & 1) &&(cnt == 2 || cnt ==3) ){
                    board[i][j] |= 2;
                }
                if(!(board[i][j] & 1) && cnt == 3){
                    board[i][j] |= 2;
                }
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                board[i][j] >>= 1;
            }
        }
}

