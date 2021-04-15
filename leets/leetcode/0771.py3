class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        found = 0
        for stone in stones:
            if (stone in jewels):
                found += 1
        return (found)