class Solution:
    def balancedStringSplit(self, s: str) -> int:
        splits = 0
        pair = 0
        for c in s:
            if (c == 'L'):
                pair += 1;
            if (c == 'R'):
                pair -= 1;
            if (pair == 0):
                splits += 1
        return (splits)