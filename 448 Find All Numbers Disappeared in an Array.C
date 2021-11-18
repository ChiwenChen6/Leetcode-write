

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
   int i =0;
   int count=0;
   int *arr = malloc(sizeof(int)*numsSize);
    
   for(i=0;i<numsSize;i++) {
       if(nums[abs(nums[i])-1]>0) {
           nums[abs(nums[i])-1]*=-1;
       }
   }
   
   for(i=0;i<numsSize;i++) {
       if(nums[i]>0) {
           arr[count++]=i+1;
       }
   }
   *returnSize = count;
  return arr;
}


Runtime: 100 ms, faster than 63.64% of C online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 17.5 MB, less than 64.20% of C online submissions for Find All Numbers Disappeared in an Array
