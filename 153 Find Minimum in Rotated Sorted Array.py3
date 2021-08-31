class Solution:
    def findMin(self, nums: List[int]) -> int:    
        start, end = 0, len(nums) - 1

        while start < end:

            mid = start + (end - start) // 2

            if nums[mid] > nums[end]:
                start = mid + 1

            else:
                end = mid

        return nums[start]
      
      
      
#       Runtime: 36 ms, faster than 88.46% of Python3 online submissions for Find Minimum in Rotated Sorted Array.
# Memory Usage: 14.5 MB, less than 84.70% of Python3 online submissions for Find Minimum in Rotated Sorted Array.
