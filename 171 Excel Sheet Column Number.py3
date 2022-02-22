class Solution(object):
    def titleToNumber(self, columnTitle):
        """
        :type columnTitle: str
        :rtype: int
        """
        result = 0
        for i in columnTitle:
            d = ord(i)-ord('A')+1
            result = result*26+d

        return result
