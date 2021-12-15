

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int len = (1<<numsSize);
    int** result = (int**)malloc(len*sizeof(int*));
    int i,pos,idx,temp;

    (*returnColumnSizes) = (int*)calloc(len,sizeof(int));
    
    for(i=0;i<len;i++)
    {
        result[i] = (int*)malloc(numsSize*sizeof(int));
    }
    
    for(i=0;i<len;i++)
    {
        temp = i;
        pos = numsSize-1;
        idx = 0;
        while(temp)
        {
            if(temp&1)
                result[i][idx++] = nums[pos];
            temp>>=1;
            pos--;
        }
        (*returnColumnSizes)[i] = idx;
    }
    
    *returnSize = len;
    return result;
}
