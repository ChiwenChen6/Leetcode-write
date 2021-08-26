class Solution:
    def intToRoman(self, num: int) -> str:
        d = {1000: 'M', 900: 'CM', 500: 'D', 400: 'CD', 100: 'C', 90: 'XC', 50: 'L', 40: 'XL', 10: 'X', 9: 'IX', 5: 'V', 4: 'IV', 1: 'I'}            
        ans = ''      
        for val, string in d.items(): 
            while num // val != 0: 
                ans += string 
                num -= val 
        
        return ans 
      
#       Runtime: 102 ms, faster than 5.02% of Python3 online submissions for Integer to Roman.
# Memory Usage: 14.1 MB, less than 95.37% of Python3 online submissions for Integer to Roman.
