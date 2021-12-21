class Solution:
    def reverse(self, x: int) -> int:
        if x<0:
            res=x*(-1)
        else:
            res=x
        res = int(str(res)[::-1])
        
        if x<0:
            res = res*(-1)
        if res<-2**31 or res>2**31-1:
            return 0
        else:
            return res
