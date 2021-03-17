class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        rst = 0
        bottom = prices[0]
        top = 0
        for ii in prices:
            if top == 0:
                if ii<bottom:
                    bottom = ii
                elif ii > bottom + fee:
                    top = ii
            else:
                if ii>top:
                    top=ii
                elif ii < top - fee:
                    rst += top - bottom - fee
                    bottom = ii
                    top = 0
        if top > 0:
            rst += top - bottom - fee
        return rst
