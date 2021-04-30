class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        final = []

        for i, num in enumerate(prices):
            take = 0
            for j in range(i + 1, len(prices)):
                if (prices[j] <= prices[i]):
                    take = prices[j]
                    break
            final += [num - take]

        return (final)