class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l=1
        r=result=max(piles)
        while l<=r:
            count=0
            mid=(l+r)//2
            for ele in piles:
                count+=math.ceil(ele/mid)
            if count<=h:
                result=min(result,mid)
                r=mid-1
            else:
                l=mid+1
        return result
