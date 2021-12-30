class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if (k % 2 == 0) or (k % 5 == 0):
            return -1
        
        N = 0
        i = 1
        while (i <= k):
            N = (N*10 + 1) % k;
            if (N == 0):
                return i
            i = i + 1
        return -1

      
      
===========================================      
      
class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        num=str(k)
        if num[-1] in {'2','4','5','6','8','0'}:
            return -1
        tem=1
        while tem%k!=0:
            tem=tem*10+1
        return len(str(tem))
