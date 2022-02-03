class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        L = len(nums)
        if L == k: return

        k = k%L # the case when k > L
        nums.reverse()

        for i in range(k//2):
            nums[i], nums[k-1-i] = nums[k-1-i], nums[i]

        for i in range(k, (L+k)//2):
            nums[i], nums[L-1-i+k] = nums[L-1-i+k], nums[i]
