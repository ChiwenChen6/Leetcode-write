

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* beautifulArray(int N, int* returnSize) {
    int *ret=(int*)calloc(2*N,sizeof(int));
    int count=0;
    ret[count++]=1;
    while (count<N) {
        for(int i=0; i<count; i++){
            ret[i]=ret[i] * 2 - 1;
            ret[count+i]=ret[i] + 1;
        }
        count*=2;
    }
    if(count>N) {
        for(int i=0; i<count; i++){
            if(ret[i]>N) {
                ret[i] = -1;
            }
        }
        int index=0;
        for(int i=0; i<count; i++){
            if(ret[i]!=-1) {
                ret[index++]=ret[i];
            }
        }
    }
    *returnSize=N;
    return ret;

}

// Runtime: 8 ms, faster than 100.00% of C online submissions for Beautiful Array.
// Memory Usage: 6.5 MB, less than 100.00% of C online submissions for Beautiful Array.
