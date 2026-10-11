class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        min_price = prices[0]
        profit = 0

        for i in range (1,len(prices)):
            max_profit = prices[i] - min_price
            if max_profit>profit:
                profit = max_profit
            min_price = min(prices[i], min_price)
        return profit 
        