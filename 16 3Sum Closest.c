

int cmp(void* a,void* b){
    return *(int*)a - *(int*)b;
}
int abs(int a){
    return a>0?a:-a;
}

int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums,numsSize,sizeof(int),cmp);
    int ret = 0;
    int grap = INT_MAX;
    int** map = (int**)malloc(numsSize*sizeof(int*));
    for(int k=0;k<numsSize;k++){
        map[k] = (int*)calloc(numsSize,sizeof(int));
        for(int i=1; i+k<numsSize; i++){
            map[k][i+k] = nums[k] + nums[i+k];
        }
    }
    
    int i = 0;
    int j = 0;
    int k = 0;
    for(i=0; i<numsSize; i++){
        for(j=i+1; j<numsSize-1; j++){
            for(k=j+1; k<numsSize; k++){
                int temp = map[i][j] + nums[k];
                if(grap > abs(temp-target)) {
                    grap = abs(temp-target);
                    ret = temp;
                }
                if(temp > target){
                    break;
                }
            }
        }
    }
    return ret;
}


// 131 / 131 test cases passed.
// Status: Accepted
// Runtime: 140 ms
// Memory Usage: 20.1 MB
// Submitted: 0 minutes ago
