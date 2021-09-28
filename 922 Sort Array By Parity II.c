

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize){
    int odd=1,even=0,i;
    int *retarr=malloc(sizeof(int)*numsSize);
    for (i=0; i<numsSize; ++i) {
        if (nums[i]%2 == 0) {
            retarr[even] = nums[i];
            even+=2;
        } else {
            retarr[odd] = nums[i];
            odd+=2;
        }
    }
    *returnSize=numsSize;
    return retarr;
}
