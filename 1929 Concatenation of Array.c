

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    int *arr=(int*)malloc(sizeof(int)*2*numsSize);
    int i=0,k=0;
    for(i=0;i<numsSize;i++) {
        arr[k++]=nums[i];
        arr[numsSize+i]=nums[i];
    }
    *returnSize=2*numsSize;
    return arr;
}
