

int maxProduct(int* nums, int numsSize){
    int max = nums[0];
    int sum;
    
    for (int i=0; i<numsSize; i++){
        sum = nums[i];
        if (sum >= max)
                max = sum;
        for (int k=i+1; k<numsSize; k++){
            sum *= nums[k];
            if (sum >= max)
                max = sum;
        }
    }
    return max;
}
