

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructArray(int n, int k, int* returnSize){

    int* set = (int*)malloc(n * sizeof(int));
    *returnSize = n;
    int i = 1;
    set[0] = 1;
    int mult = 1;
    int offset = (int)(k / 2.0) + 1;
    
    for(k; k > 0; k--){
        set[i] = set[i - 1] + k * mult;
        mult = -1 * mult;
        i++;
        
    }
    if(i == n) {
        return set;
    }
    set[i] = set[i - 1] + offset;
    i++;    
    for(i; i < n; i++){
        set[i] = set[i - 1] + 1;
    }
    return set;
}

//n = 10 and k = 5

// 1: 1
// 2: 1 + k = 6
// 3: 6 - (k - 1) = 2
// 4: 2 + (k - 2) = 5
// 5: 5 - (k - 3) = 3
// 6: 3 + (k - 4) = 4

// 7: 4 + floor(k / 2) + 1 = 4 + 2 + 1 = 7
// 8: 8
// 9: 9
// 10: 10


// Status: Accepted
// Runtime: 24 ms
// Memory Usage: 9.2 MB
