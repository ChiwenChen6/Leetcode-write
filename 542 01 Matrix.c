int** find_minus_one(int** ret, int matrixSize, int* matrixColSize,int row,int col,int* size){
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int** result=(int**)malloc(4*sizeof(int*));
    (*size)=0;
    for(int i=0;i<4;i++){
        int x=row+dir[i][0];
        int y=col+dir[i][1];
        if(x>-1&&x<matrixSize&&y>-1&&y<matrixColSize[0]){
            if(ret[x][y]==-1){
                result[(*size)++]=(int*)malloc(2*sizeof(int));
                result[(*size)-1][0]=x;
                result[(*size)-1][1]=y;
            }
        }
    }
    return result;
}
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    *returnSize=matrixSize;
    returnColumnSizes[0]=matrixColSize;
    int** stack = (int**)malloc(matrixSize*matrixColSize[0]*sizeof(int*));
    int count=0;
    int** ret=(int**)malloc(matrixSize*sizeof(int*));
    for(int i=0;i<matrixSize;i++){
        ret[i]=(int*)malloc(matrixColSize[i]*sizeof(int));
        for(int j=0;j<matrixColSize[i];j++){
            if(matrix[i][j]==0){
                ret[i][j]=0;
                stack[count++]=(int*)malloc(2*sizeof(int));
                stack[count-1][0]=i;
                stack[count-1][1]=j;
            }else{
                ret[i][j]=-1;
            }
        }
    }
    while(count>0){
        int** stack_tmp = (int**)malloc(matrixSize*matrixColSize[0]*sizeof(int*));
        int count_tmp=0;
        for(int i=0;i<count;i++){
            int x=stack[i][0];
            int y=stack[i][1];
            free(stack[i]);
            int size=0;
            int** tmp=find_minus_one(ret, matrixSize, matrixColSize,x,y,&size);
            for(int j=0;j<size;j++){
                ret[tmp[j][0]][tmp[j][1]]=ret[x][y]+1;
                stack_tmp[count_tmp++]=(int*)malloc(2*sizeof(int));
                stack_tmp[count_tmp-1][0]=tmp[j][0];
                stack_tmp[count_tmp-1][1]=tmp[j][1];
            }
        }
        free(stack);
        stack=stack_tmp;
        count=count_tmp;
    }
    return ret;
}


// Runtime: 232 ms, faster than 12.90% of C online submissions for 01 Matrix.
// Memory Usage: 53.8 MB, less than 6.45% of C online submissions for 01 Matrix.
