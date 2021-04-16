class Solution:
    def fib(self, n: int) -> int:
        if n < 2:
            return n
        
        a = 0
        b = 1
        for _ in range(1,n):
            a, b = b, a+b
        return b
      
#       04/16/2021 11:23	Accepted	28 ms	14.4 MB	python3
