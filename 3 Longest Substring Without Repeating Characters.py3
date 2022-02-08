class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        a = 0
        b = 0
        maxLength = 0
        dic = {}
        if len(s) <2:
            return len(s)

        for tmp, check in enumerate(s):
            if check not in dic or a > dic[check]:
                dic[check] = tmp
                b += 1
                maxLength = max(maxLength, b-a)
            else:
                a = dic[check] + 1
                dic[check] = tmp
                b +=1
                maxLength = max(maxLength, b-a)

        return maxLength
