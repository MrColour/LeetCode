class Solution:
    def countVowelStrings(self, n: int) -> int:
        ends = [1] * 5

        for i in range(1, n):
            copy = ends.copy()
            for b in range(5):
                ends[b] = sum(copy[:b + 1])

        return (sum(ends))