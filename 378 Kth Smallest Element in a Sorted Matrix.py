

"""
Created on Wed Nov. 11 21:24 2020

@author: Chiwen Chen
"""
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        allnumarr=[]
        for arra in matrix:
            allnumarr += arra
        return sorted(allnumarr)[k-1]

"""Runtime: 156 ms, faster than 93.03% of Python3 online submissions for Kth Smallest Element in a Sorted Matrix.
Memory Usage: 19.9 MB, less than 9.31% of Python3 online submissions for Kth Smallest Element in a Sorted Matrix."""