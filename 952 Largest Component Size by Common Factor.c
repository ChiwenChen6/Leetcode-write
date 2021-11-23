int parent[131072];

int find(int x)
{
    if(parent[x] == -1)
        return x;
    else 
        return parent[x] = find(parent[x]);
}
bool uni(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if(x != y)
        parent[y] = x;
    else 
        return false;
    return true;
}

int largestComponentSize(int* nums, int numsSize){
    int temp[131072] = {0};
    int ret = 0;
    for(int i = 0; i < 131072; i++)
        parent[i] = -1;
    for(int i = 0; i < numsSize; i++)
        for(int j = 2; j*j <= nums[i]; j++)
            if(nums[i] % j == 0)
            {
                uni(j, nums[i]);
                uni(nums[i], nums[i]/j);
            }
    for(int i = 0; i < numsSize; i++)
        ret = ret > ++temp[find(nums[i])] ? ret : temp[find(nums[i])];
    return ret;
}
