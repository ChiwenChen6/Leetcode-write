class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        count={}
        for i in nums:
            if i not in count:
                count[i]=1
            else:
                return i
