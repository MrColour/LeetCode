class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        choices = sorted(piles, reverse=True)

        choices = choices[0:len(choices) * 2 // 3]
        coins = choices[1::2]

        return (sum(coins))
        