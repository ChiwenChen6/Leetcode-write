class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        n=len(nums)
        nums.sort()
        
        i=0
        j=1
        s=set()
        while i<n and j<n:
            t=nums[j]-nums[i]
            if t==k:
                s.add((nums[i],nums[j]))
                i += 1
                j += 1
                
            elif t>k and i+1<j:
                i += 1
                
            else:
                j+=1
                
        return len(s)
