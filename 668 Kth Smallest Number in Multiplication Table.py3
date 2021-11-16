class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        start = 1
        end = m * n
        while start < end:
            mid = (start + end) // 2
            curr = 0
            j = 1
            for r in range(m, 0, -1):
                while j <= n and r * j <= mid:
                    j += 1
                curr += j-1
            if curr < k:
                start = mid + 1
            else:
                end = mid
        return start
