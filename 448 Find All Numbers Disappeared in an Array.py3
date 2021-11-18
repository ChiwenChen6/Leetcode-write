class Solution:
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        i = j = 0
        new_nums=[]
        for i in range(len(nums)):
            if nums[abs(nums[i]) - 1] > 0:
                nums[abs(nums[i])  - 1] = -nums[abs(nums[i]) - 1]
        for j in range(len(nums)):
            if nums[j] > 0:
                new_nums.append(j + 1)
        return new_nums
                
