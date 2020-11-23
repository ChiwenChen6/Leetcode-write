
"""
Created on Sun Nov. 22 15:33 2020

@author: Chiwen Chen
"""
///用動態算法 把全部弄出列表


int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int row=obstacleGridSize;
    int col= *obstacleGridColSize;
    unsigned int ratmap[row][col];    
    //row col 要記得  row --- COL|||
    ratmap[0][0]=(obstacleGrid[0][0]==0)?1:0;//一定有起始 先設為零 並且讓迴圈減少這一格    
    for(int i=1;i<row;++i){
        ratmap[i][0]=(obstacleGrid[i][0]==1)?0:(ratmap[i-1][0]);
    }    
    for(int j=1;j<col;++j){
        ratmap[0][j]=(obstacleGrid[0][j]==1)?0:(ratmap[0][j-1]);
    }    
    //做完單邊之後來算總和
    for(int i=1;i<row;++i){
        for(int j=1;j<col;++j){
            ratmap[i][j]=(obstacleGrid[i][j]==1)?0:(ratmap[i-1][j]+ratmap[i][j-1]);
        }   
    }    
    return ratmap[row-1][col-1];
}



"""Runtime: 4 ms, faster than 75.44% of C online submissions for Unique Paths II.
Memory Usage: 6 MB, less than 92.98% of C online submissions for Unique Paths II."""