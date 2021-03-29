class Solution:
    def originalDigits(self, s: str) -> str:
        # zero one two three four five six seven eight nine 
        
        #0 z
        #2 w
        #4 u
        #6 x
        #8 g
        
        #1 o - 0 -2 -4 
        #3 h - 8
        #5 v - 7
        #7 s - 6
        #9 i - 5 -6 -8
        
        
        res = ""
        res += "0"*s.count('z')
        res += "1"*(s.count('o') - s.count('z') - s.count('w') - s.count('u'))
        res += "2"*s.count('w')
        res += "3"*(s.count('h') - s.count('g'))
        res += "4"*s.count('u')
        res += "5"*(s.count('v') - s.count('s') + s.count('x'))
        res += "6"*s.count('x')
        res += "7"*(s.count('s') - s.count('x'))
        res += "8"*s.count("g")
        res += "9"*(s.count('i') - s.count('x') - s.count("g") - s.count('v') + s.count('s') - s.count('x'))
        
        return res

    
#     Runtime: 32 ms, faster than 99.40% of Python3 online submissions for Reconstruct Original Digits from English.
# Memory Usage: 14.5 MB, less than 66.67% of Python3 online submissions for Reconstruct Original Digits from English.
