class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        if len(palindrome) == 1:   
            return ""
        for i in range(len(palindrome)):
            if palindrome[i] != 'a' and i != len(palindrome) - i - 1:   
                return palindrome[:i] + "a" + palindrome[i+1:]  
        return palindrome[:-1] + "b"    
