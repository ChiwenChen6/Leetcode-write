class Solution:
    def hammingWeight(self, n: int) -> int:
        return bin(n).count('1')
        
          """
        count 1 in binary
        """
