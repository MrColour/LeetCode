from collections import deque

class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        nums = sorted(deck, reverse=True)
        res = deque()

        for num in nums:
            res.rotate(-1)
            res.append(num)

        res = list(res)
        return (res[::-1])