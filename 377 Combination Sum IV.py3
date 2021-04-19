class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0] * (target + 1)
        dp[0] = 1
        for i in range(target):
            if not dp[i]: continue
            for num in nums:
                if num + i <= target: dp[i+num] += dp[i]
        return dp[target]
        
