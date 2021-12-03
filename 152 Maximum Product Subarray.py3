class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curr_max = nums[0]
        curr_min = nums[0]
        final_max = nums[0]
        
        for i in range(1,len(nums)):
            temp = curr_max
            curr_max = max(max(curr_max*nums[i],curr_min * nums[i]),nums[i])
            curr_min = min(nums[i],min(curr_min*nums[i],temp * nums[i]))
            final_max = max(curr_max,final_max)
            
        return final_max 
