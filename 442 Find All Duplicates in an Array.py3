class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        count = 0
        nums.sort()
        for i in range(1,len(nums)):
            if nums[i]==nums[i-1]:
                nums[i],nums[count]=nums[count],nums[i]
                count+=1
        return nums[:count]
