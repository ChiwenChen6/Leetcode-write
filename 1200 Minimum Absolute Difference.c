int cmp (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
    qsort(arr, arrSize, sizeof(int), cmp);
    int min = arr[1] - arr[0];
    int count = 1;
    for(int i=2; i<arrSize; i++){
        if(min < arr[i] - arr[i-1]) continue;
        else if(min == arr[i] - arr[i-1]) {
            count++;
        } else{
            min = arr[i] - arr[i-1];
            count = 1;
        }
    }
    *returnSize = count;
    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    int** ans = malloc(*returnSize * sizeof(int*));
    for(int i=0; i<*returnSize; i++){
        (*returnColumnSizes)[i] = 2;
        ans[i] = malloc(2 * sizeof(int));
    }
    int index = 0;
    for(int i=1; i<arrSize; i++){
        if(min == arr[i] - arr[i-1]){
            ans[index][0] = arr[i-1];
            ans[index][1] = arr[i];
            index++;
        }
    }
    return ans;
}
