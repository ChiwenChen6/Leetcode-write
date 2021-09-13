class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:

        dict = { 'b':0, 'a':0, 'l':0, 'o':0, 'n':0 }
        for c in text:
            if c in dict:
                dict[c] += 1
        return min(dict['b'], dict['a'], dict['l']//2, dict['o']//2, dict['n'])
