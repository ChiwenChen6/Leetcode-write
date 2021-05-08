class Solution:
    def superpalindromesInRange(self, left: str, right: str) -> int:
        left, right = int(left), int(right)
        MAGIC = 100000

        def reverse(x):
            ans = str(x)[::-1]
            return int(ans)
            
        def is_palindrome(x):
            return x == reverse(x)

        ans = 0
        for k in range(MAGIC):
            s = str(k)
            t = s + s[-2::-1]
            v = int(t) ** 2
            if v > right: break
            if v >= left and is_palindrome(v):
                ans += 1
        for k in range(MAGIC):
            s = str(k)
            t = s + s[::-1]
            v = int(t) ** 2
            if v > right: break
            if v >= left and is_palindrome(v):
                ans += 1
        return ans
        
