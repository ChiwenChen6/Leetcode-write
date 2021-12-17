#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int rowSize = matrixSize;
    int colSize = *matrixColSize;
    int maxSum = 0;
    
    int dp[rowSize+1][colSize+1];
    
    for(int i=0; i<=rowSize;i++){
        for(int j=0; j<=colSize; j++){
            dp[i][j] = 0;
        }
    }
    
    int maxArea = 0;
    for(int i=1; i<=rowSize;i++){
        for(int j=1; j<=colSize; j++){
            if(matrix[i-1][j-1] == '1'){
                int tempMin = MIN(dp[i][j-1],dp[i-1][j]);
                dp[i][j] = MIN(tempMin,dp[i-1][j-1])+1;
                maxSum = MAX(maxSum, dp[i][j]);
            }
        }
    }
    return maxSum*maxSum;
}
