class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.isupper() or word==str.title(word) or word.islower():
            return True
        return False
        
