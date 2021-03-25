int cmp (const* a, const* b) {
    return ( *(int*) a - *(int*) b);
}

int *advantageCount(int *A, int ASize, int *B, int BSize, int *returnSize) {
    int *res = (int *)malloc(sizeof(int) * ASize);
    // sort B original index
    int sort_b[BSize][2];  

    for (int i = 0; i < BSize; i++) {
        sort_b[i][0] = B[i];
        sort_b[i][1] = i;
    }
    // use qsort 
    qsort(A, BSize, sizeof(int), cmp);
    qsort(sort_b, BSize, sizeof(sort_b[0]), cmp);

    int l = 0, r = BSize - 1;
    for (int i = 0; i < ASize; i++) {
        if (A[i] > sort_b[l][0]) {
            res[sort_b[l][1]] = A[i];
            l++;
        } else {
            res[sort_b[r][1]] = A[i];
            r--;
        }
    }

    *returnSize = ASize;
    return res;
}
