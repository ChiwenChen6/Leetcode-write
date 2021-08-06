class Solution:

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        #exception case
        if len(nums) == 0:
            return [[]]
        nums.sort()
        return self.subsetsWithDupHelper(nums, len(nums)-1)
        
    def subsetsWithDupHelper(self, nums: List[int], r: int) -> List[List[int]]:
        if r < 0:
            return [[]]
        
        v = nums[r]
        copyr = 1
        while r-1 >= 0:
            if nums[r-1] == v:
                copyr += 1
                r -= 1
            else:
                break
        prefix_list = self.subsetsWithDupHelper(nums, r-1)
        suffix_list = [[v]*i for i in range(1, copyr+1)]
        ret_list = []
        ret_list.extend(prefix_list)
        for p in prefix_list:
            for s in suffix_list:
                ret_list.append(p+s)
        return ret_list
      
#       Runtime: 36 ms, faster than 74.23% of Python3 online submissions for Subsets II.
# Memory Usage: 14.6 MB, less than 32.98% of Python3 online submissions for Subsets II.
