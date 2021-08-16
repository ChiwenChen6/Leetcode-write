
typedef struct NumArray{
    int size;
    int* sum;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    struct NumArray *array;
    int i;
    
    array = malloc(sizeof(struct NumArray));
    array->sum = malloc((numsSize + 1) * sizeof(int));
    array->size = numsSize;
    array->sum[0] = 0;
    for (i = 0; i < numsSize; i++) {
        array->sum[i+1] = array->sum[i] + nums[i];
    }
    return array;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    return obj->sum[j+1] - obj->sum[i];
}

void numArrayFree(NumArray* obj) {
    free(obj->sum);
    free(obj);
}


// Runtime: 20 ms, faster than 88.64% of C online submissions for Range Sum Query - Immutable.
// Memory Usage: 11.2 MB, less than 37.50% of C online submissions for Range Sum Query - Immutable.
