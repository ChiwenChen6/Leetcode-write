

int arrayNesting(int* nums, int numsSize){
    int max = 0;
    int cnt = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] != -1)
        {
            int j = nums[i]; 
            cnt = 0;
            while(j != i)
            {
                cnt++;
                int temp = nums[j];
                nums[j] = -1;
                j = temp;
            }
            cnt++;
            if(cnt > max)
                max = cnt;
        }
            
    }
    return max;
}


// Runtime: 14 ms, faster than 44.44% of C online submissions for Array Nesting.
// Memory Usage: 6.7 MB, less than 66.67% of C online submissions for Array Nesting.
