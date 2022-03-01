

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    int *numBitsArray, idx;
    numBitsArray = malloc((n + 1) * sizeof(int));
    numBitsArray[0] = 0;
    
    *returnSize = n+1;
    for (idx = 1; idx <= n; idx++) {
        numBitsArray[idx] = numBitsArray[idx >> 1] + (idx & 0x01);
    }
    
    return numBitsArray;
}
