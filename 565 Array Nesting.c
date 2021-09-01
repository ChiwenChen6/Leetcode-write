

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
