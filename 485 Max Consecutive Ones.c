
int findMaxConsecutiveOnes(int* nums, int numsSize){
    bool bIn = false;
    int maxLen = 0;
    int i;
    int from;
    
    for (i = 0; i < numsSize; i++) {
        if (nums[i]) {
            if (!bIn) {
                from = i;
                bIn = true;
            }
        }
        else {
            if (bIn) {
                int len = i - from;
                if (len > maxLen) {
                    maxLen = len;
                }
            }
            bIn = false;
        }
    }

    if (bIn) {
        int len = i - from;
        if (len > maxLen) {
            maxLen = len;
        }
    }
    
    return maxLen;
}
