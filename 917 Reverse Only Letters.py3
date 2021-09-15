class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        # get all the letters in a list
        # reverse the list of letters
        # replace the letters form s with the ones from letters
        s = list(s)
        letters = []
        for i in range(len(s)):
            if s[i].isalpha():
                letters.append(s[i]) 
        j = 0
        letters.reverse() 
        for i in range(len(s)):
            if s[i].isalpha():
                s[i] = letters[j]
                j += 1
        return "".join(s)
