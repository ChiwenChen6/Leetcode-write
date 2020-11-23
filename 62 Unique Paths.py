
"""
Created on Sun Nov. 22 11:21 2020

@author: Chiwen Chen
"""



class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        """C(m+n-2, n-1) """
        factorialup=1
        factorialdn1=factorialdn2=1
        """注意 範圍是 1~k+1 k為階層 range記得要加1"""
        """m+n-2! /(m-1*n-1!) 因為要加一 也可以寫成 m+n-1 m n """
        
        for i in range(1,m+n-2+1):
            factorialup = factorialup*i
        for j in range(1,n-1+1):
            factorialdn1 = factorialdn1*j   
        for jj in range(1,(m+n-2)-(n-1)+1):
            factorialdn2 = factorialdn2*jj   
        
        return int(factorialup/(factorialdn1*factorialdn2))

"""Runtime: 36 ms, faster than 12.72% of Python3 online submissions for Unique Paths.
Memory Usage: 14.2 MB, less than 36.72% of Python3 online submissions for Unique Paths."""