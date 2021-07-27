class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        closest = -1
        diff = float("inf") //宣告無限大
        for i in range(n - 2):
            start = i + 1
            end = n - 1
            while start < end:
                curr_sum = nums[i] + nums[start] + nums[end]
                if curr_sum == target:
                    return target
                if abs(curr_sum - target) < diff:
                    diff = abs(curr_sum - target)
                    closest = curr_sum
                
                if curr_sum < target:
                    start += 1
                else:
                    end -= 1
                    
        return closest
      
      
# Runtime: 116 ms, faster than 84.83% of Python3 online submissions for 3Sum Closest.
# Memory Usage: 14.3 MB, less than 41.99% of Python3 online submissions for 3Sum Closest.
