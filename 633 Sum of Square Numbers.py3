class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        if c==0:
            return True
        for i in range(1,int(c**(1/2))+1):
            if floor((c-i**2)**(.5))==ceil((c-i**2)**(.5)):
                return True
        return False
