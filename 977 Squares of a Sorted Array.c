

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
   * returnSize=numsSize;
    int i,j,temp,a;
    for(i=0;i<numsSize;i++)
    {
        a=nums[i];
        nums[i]=a*a;
    }
    for(i=0;i<numsSize;i++)
    {
        for(j=0;j<numsSize-i-1;j++)
        {
            if(nums[j]>nums[j+1])
            {
                temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
    return nums;
}
