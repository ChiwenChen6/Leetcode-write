class Solution:
    def __init__(self):
        self.time = None
        self.totalTrips = None
        
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        self.time = time
        self.totalTrips = totalTrips
        left = 1
        right = 0
        for t in self.time:
            right = max(right, t)
        right = right * self.totalTrips
        ans = right
        while left <= right:
            mid = (left + right) // 2
            if self.check(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans
    
    def check(self, givenTime):
        actualTrips = 0
        for t in self.time:
            actualTrips += givenTime // t
        if actualTrips >= self.totalTrips:
            return True
        return False
