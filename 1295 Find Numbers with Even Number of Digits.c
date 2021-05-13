

int findNumbers(int* nums, int numsSize){
    int c = 0;
    int *n = nums;
    int sz = numsSize;
    while (sz--)
        c += (*n == 100000) || (*n >= 10 && *n <= 99) || (*n >= 1000 && *n <= 9999), n++;
    return c;
}


// Runtime: 0 ms, faster than 100.00% of C online submissions for Find Numbers with Even Number of Digits.
// Memory Usage: 5.9 MB, less than 89.95% of C online submissions for Find Numbers with Even Number of Digits.
