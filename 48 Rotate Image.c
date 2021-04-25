

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int size = matrixSize - 1;
    int tmpA;
    int tmpB;
    int tmpC;
    int tmpD;  
    for (int i = 0; i < matrixSize/2; i++){
        for (int j = i; j < size-i; j++){
            tmpA = matrix[i][j];
            tmpB = matrix[j][size-i];
            tmpC = matrix[size-i][size-j];
            tmpD = matrix[size-j][i];
            
            matrix[i][j] = tmpD;
            matrix[j][size-i] = tmpA;
            matrix[size-i][size-j]=tmpB;
            matrix[size-j][i] = tmpC;
        }
    }
}

// Status: Accepted
// Runtime: 4 ms
// Memory Usage: 6.3 MB
