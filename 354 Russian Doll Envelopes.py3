class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        dp = []
        for _,height in envelopes:
            left = bisect_left(dp, height)
            if left == len(dp): dp.append(height)
            else: dp[left] = height
        return len(dp)
        
        
# Runtime: 140 ms, faster than 96.81% of Python3 online submissions for Russian Doll Envelopes.
# Memory Usage: 16.4 MB, less than 57.35% of Python3 online submissions for Russian Doll Envelopes.
