class Solution:
    def findNumbers(self, nums: List[int]):
        count = 0
        new = map(str, nums)
        for i in new:
            if len(i) % 2 == 0:
                count += 1
        return count
