int cmp(void const *a, void const *b) {
    return (*(int *)a - *(int *)b);
}

int maxOperations(int* nums, int numsSize, int k){
	qsort(nums, numsSize, sizeof(int), cmp);
	int head = 0, end = numsSize - 1;
	int i, sum, answer = 0;
	printf("sort_complete\n");
	for(i = 0; i < numsSize; i++)
	{
		sum = nums[head] + nums[end];
		if(head >= end)
		{
			break;
		}
		if(sum > k)
		{
			end -= 1;
		}
		else if(sum < k)
		{
			head += 1;
		}
		else if(sum == k)
		{
			answer++;
			head += 1;
			end -= 1;
		}
	}
	return answer;
}
