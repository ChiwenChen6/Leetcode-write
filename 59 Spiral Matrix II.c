

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){

    int ** result = (int **)malloc(n*sizeof(int *));
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++) {
        result[i] = (int *)malloc(n*sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    int left = 0;
    int right = n-1;
    int up = 0;
    int down = n-1;
    int count = 1;
    
    while(left <= right && up <= down){
        for(int i=left; i<=right; i++){
            //left to right
            result[up][i] = count++;
        }
        for(int i=up+1; i<=down; i++) {
            //up to down
            result[i][right] = count++; 
        }
        for(int i=right-1; i>left && up != down; i--) {
            //right to left
            result[down][i] = count++;
        }
        for(int i=down; i>up && left != right; i--) {
            //down to up
            result[i][left] = count++;
        }
        up++; 
        down--; 
        left++; 
        right--;
    }
    return result;
}
