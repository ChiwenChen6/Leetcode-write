class Solution:
    def reverseWords(self, s: str) -> str:
        parts = s.strip().split(' ')
        ret = ''
        for e in reversed(parts):
            tmp = e.strip()
            if tmp:
                if ret:
                    ret += ' '
                ret += tmp
        return ret
        
        
#         Runtime: 28 ms, faster than 91.83% of Python3 online submissions for Reverse Words in a String.
# Memory Usage: 14.6 MB, less than 12.23% of Python3 online submissions for Reverse Words in a String.
