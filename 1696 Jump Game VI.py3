class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        l=len(nums)
        Table=[0]*l
        Table[0]=nums[0]
        max,a=Table[0],0
        for i in range(1,l):
            if a<i-k:
                z=i-1
                max=-1000000000
                while i-z<=k and z>=0:
                    
                    if Table[z]>max:
                        max=Table[z]
                        a=z
                    z=z-1
            Table[i]=max+nums[i]
            if Table[i]>max:
                max,a=Table[i],i
        return Table[-1]
