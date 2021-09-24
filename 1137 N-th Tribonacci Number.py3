class Solution:
    def tribonacci(self, n: int) -> int:
        d = [0, 1, 1]
        if n == 0 :
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 1
        
        for i in range(3, n + 1):
            d.append(0)
            d[i] = d[i-1]+d[i-2]+d[i-3]
        
        return d[n]
