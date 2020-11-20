"""
Created on Mon Nov. 16 23:25 2020

@author: Chiwen Chen
"""



void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int size=matrixSize;
    //printf("%d\n", matrixSize);
    //printf("%d\n", *matrixColSize);
    for (int i=0;i<matrixSize/2;i++)
    {
        for (int j=i;j<size-i-1;j++)
        {
            int tmp1=matrix[i][j];
            int tmp2=matrix[j][size-1-i];
            int tmp3=matrix[size-1-i][size-1-j];
            int tmp4=matrix[size-1-j][i];
            matrix[i][j]= tmp4;
            matrix[j][size-1-i]=tmp1;
            matrix[size-i-1][size-1-j]=tmp2;
            matrix[size-j-1][i]=tmp3;
        }
    }
}

"""Runtime: 4 ms, faster than 83.94% of C online submissions for Rotate Image.
Memory Usage: 6.5 MB, less than 39.45% of C online submissions for Rotate Image."""



