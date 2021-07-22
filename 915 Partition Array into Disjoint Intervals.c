

int partitionDisjoint(int* nums, int numsSize){
    int* array = (int*)malloc(numsSize*sizeof(int));
    int max = -1;
    for(int i=0; i<numsSize; i++){
        max = max>nums[i] ? max:nums[i];
        array[i] = max;
    }
    int* dp = (int*)malloc(numsSize*sizeof(int));
    dp[0] = 1;
    for(int i=1; i<numsSize; i++){
        dp[i] = nums[i]<array[dp[i-1]-1] ? i+1:dp[i-1];
    }
    free(array);
    return dp[numsSize-1];
}


// Runtime: 24 ms, faster than 66.67% of C online submissions for Partition Array into Disjoint Intervals.
// Memory Usage: 9 MB, less than 11.11% of C online submissions for Partition Array into Disjoint Intervals.
