

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
        int j = 0;
        int index = 0;
        int* arr=(int*)malloc(numsSize*sizeof(int));
        for(int i=0; i<numsSize; i++) {
            index=abs((abs(nums[i])-1));
            if(nums[index]>0) {
                nums[index]*=-1;
            }
            else{
                arr[j++]=abs(nums[i]);
            }
        }
        *returnSize=j;
        return arr;
}
