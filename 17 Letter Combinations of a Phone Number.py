class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        buttons = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        n = len(digits)
        answer = []
        if n == 1:
            for ch1 in buttons[int(digits[0])-2]:
                answer.append(ch1)
        elif n == 2:
            for ch1 in buttons[int(digits[0])-2]:
                for ch2 in buttons[int(digits[1])-2]:
                    answer.append(''.join([ch1, ch2]))
        elif n == 3:
            for ch1 in buttons[int(digits[0])-2]:
                for ch2 in buttons[int(digits[1])-2]:
                    for ch3 in buttons[int(digits[2])-2]:
                        answer.append(''.join([ch1, ch2, ch3]))

        elif n == 4:
            for ch1 in buttons[int(digits[0])-2]:
                for ch2 in buttons[int(digits[1])-2]:
                    for ch3 in buttons[int(digits[2])-2]:
                        for ch4 in buttons[int(digits[3])-2]:
                            answer.append(''.join([ch1, ch2, ch3, ch4]))

        return answer
        
        
# Status: Accepted
# Runtime: 32 ms
# Memory Usage: 14.1 MB



class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits: return []
        mappings = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz'}
        result = []
        def construct(idx=0, partial=[]):
            if idx >= len(digits):
                result.append(''.join(partial))
                return
            for ch in mappings[digits[idx]]:
                partial.append(ch)
                construct(idx+1, partial)
                partial.pop()

        construct()
        return result   
      
# Status: Accepted
# Runtime: 28 ms
# Memory Usage: 14.2 MB
