class Solution:
    def halvesAreAlike(self, s: str) -> bool:      
        res = 0
        vowels = set()
        for ch in 'aeiouAEIOU':
            vowels.add(ch)
        for ch in s[:len(s) // 2]:
            if ch in vowels:
                res += 1
        for ch in s[len(s) // 2:]:
            if ch in vowels:
                res -= 1
        return res == 0
        
# Status: Accepted
# Runtime: 28 ms
# Memory Usage: 14.4 MB
