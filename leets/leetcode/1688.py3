class Solution:
    def numberOfMatches(self, n: int) -> int:
        played = 0
        while (n > 1):
            played += n // 2
            if (n % 2 == 1):
                n += 1
            n //= 2
        return (played)