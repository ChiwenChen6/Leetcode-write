
void sortColors(int* nums, int numsSize)
{
    int *left = nums;
    int *right = nums + numsSize - 1;
    int tmp;
    
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            tmp = *left;
            *left = nums[i];
            nums[i] = tmp;
            left++;
        }
      
    }
        for (int i = numsSize; i > 0; i--)
    {
        if (nums[i - 1] == 2 )
        {
            tmp = *right;
            *right = nums[i - 1];
            nums[i - 1] = tmp;
            right--;
        }        
    }   
}

// Runtime: 0 ms, faster than 100.00% of C online submissions for Sort Colors.
// Memory Usage: 6.1 MB, less than 35.45% of C online submissions for Sort Colors.
