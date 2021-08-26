class Solution:
    def numberToWords(self, num: int) -> str:
        A = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        B = ["Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        C = ["Billion", "Million", "Thousand"]
        def trans(n):
            return [] if not n else [A[n // 100], "Hundred"] + trans(n%100) if n >= 100 else [A[n]] if n < 20 else [B[(n//10)-2]] + trans(n%10)
                    
        res, N = [], [10**9, 10**6, 1000, 1]
        for i in range(4):
            digit, num = divmod(num, N[i])
            if digit: res += trans(digit) + C[i:i+1]
        return " ".join(res) or "Zero"
      
#       Runtime: 55 ms, faster than 5.88% of Python3 online submissions for Integer to English Words.
# Memory Usage: 14.3 MB, less than 76.24% of Python3 online submissions for Integer to English Words.
