int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize){
    int pre = -1;
    int idx = 0;
    qsort(nums, numsSize, sizeof(int), cmp); 
    int max = 1, dp[numsSize];
    int * result = (int *)malloc(1000*sizeof(int));

    for(int i = 0; i < numsSize; i++){
        dp[i] = 1;
    }
    for(int i = 1; i < numsSize; i++){
        for(int j = 0; j < i; j++){
            if((nums[i] % nums[j] == 0) && (dp[i] < dp[j] + 1))
            {
                dp[i] = dp[j] + 1;
                max = max > dp[i] ? max : dp[i];
            }
        }
    }
    for(int i = numsSize - 1; i >= 0; i--) {
        if(dp[i] == max && (pre % nums[i] == 0 || pre == -1)) {
            result[idx++] = nums[i];
            max--;
            pre = nums[i];
        }
    }
    *returnSize = idx;
    return result;
}


// Runtime: 20 ms, faster than 83.33% of C online submissions for Largest Divisible Subset.
// Memory Usage: 6.3 MB, less than 33.33% of C online submissions for Largest Divisible Subset.
