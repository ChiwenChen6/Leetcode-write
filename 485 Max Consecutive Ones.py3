class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        temp = []
        result = 0
        
        for i in range(0, len(nums)):
            if nums[i] == 1:
                temp.append(nums[i])
            else:
                result = max(result, len(temp))
                temp.clear()
        
        return max(result, len(temp))
