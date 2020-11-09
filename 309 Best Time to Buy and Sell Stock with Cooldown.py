class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        if not prices or len(prices) < 2: return 0
        n = len(prices);
        buy, sell = [0] * n, [0] * n;
        buy[0] = -prices[0];
        buy[1] = max(-prices[0], -prices[1]);
        sell[1] = max(0, prices[1] - prices[0]);
        for i in range(2, n):
            buy[i] = max(sell[i - 2] - prices[i], buy[i - 1]);
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);

        return sell[n - 1]

"""
create two array, buy and sell. buy[i] means we buy a stock at day i , and sell[i] means we sell a stock at day i.
"""


"""
Runtime: 40 ms, faster than 63.84% of Python3 online submissions for Best Time to Buy and Sell Stock with Cooldown.
Memory Usage: 14.4 MB, less than 5.62% of Python3 online submissions for Best Time to Buy and Sell Stock with Cooldown.
"""