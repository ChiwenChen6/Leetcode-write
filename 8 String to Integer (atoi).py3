class Solution:
    def myAtoi(self, s: str) -> int:
        matchnum = re.match(' *[+-]?\d+',s)
        if not matchnum:
            return 0
        if matchnum:
            matchnum=int(matchnum.group(0))
            if matchnum > 2147483647:
                return 2147483647
            if matchnum < -2147483648:
                return -2147483648
            else:
                return matchnum
