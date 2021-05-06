

int jump(int* nums, int numsSize) {
    
    int nextNum = nums[0];
    int right = nextNum;
    int jumps = 0;

    for(int i=1; i<numsSize; ++i) {
        if(--nextNum < nums[i]) {
            nextNum = nums[i];
        }
        if(i == right || i == numsSize-1) {
            jumps++;
            right += nextNum;
        }
    }
    return jumps;
}
