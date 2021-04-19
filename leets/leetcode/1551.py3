class Solution:
    def minOperations(self, n: int) -> int:
        diff = []
        to = n
        for i in range(n // 2):
            diff += [to - 1]
            to -= 2

        return (sum(diff))