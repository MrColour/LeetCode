class Solution:
    def minPartitions(self, n: str) -> int:
        most = 0
        for l in n:
            if (int(l) > most):
                most = int(l)
        return (most)