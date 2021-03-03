int missingNumber(int* nums, int numsSize){
    int mis_num = numsSize;
    for(int i =0; i < numsSize; i++)
        misnum ^= nums[i] ^ i;
    return mis_num;
}
