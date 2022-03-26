class Solution:
    def search(self, nums: List[int], target: int) -> int:
        i, j = 0, len(nums) - 1
        mid = (i + j) // 2
        while(i <= j):
            if(nums[mid] == target): return mid
            elif(nums[mid] < target): i = mid + 1
            else: j = mid - 1
            mid = (i + j) // 2
        return -1
