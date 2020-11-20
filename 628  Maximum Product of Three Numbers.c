
"""
Created on Thurs Nov. 12 16:36 2020

@author: Chiwen Chen
"""


int max(int a, int b) {
  if (a>b)
    return a;
  else
    return b;
}

int maximumProduct(int* nums, int numsSize){
    int temp;
    int T=numsSize;
    //常常忘記要記得加cmp
    int cmp ( const void *a , const void *b )
    {
        return *(int *)a - *(int *)b;
    }
    qsort(nums,numsSize,sizeof(nums[0]),cmp);
    temp=max(nums[T-1]*nums[T-2]*nums[T-3],nums[0]*nums[1]*nums[T-1]);
    return temp;
}
"""
Runtime: 52 ms, faster than 17.24% of C online submissions for Maximum Product of Three Numbers.
Memory Usage: 8.5 MB, less than 20.69% of C online submissions for Maximum Product of Three Numbers.
"""