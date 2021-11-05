class Solution:
    def arrangeCoins(self, n: int) -> int:
        if n == 0:
            return(0)
        else:
            m = 1
            tot = 0
            i = 1
            while True:
                tot += m
                if tot > n:
                    return(m-1)
                elif tot == n:
                    return(m)
                else: 
                    m += 1
