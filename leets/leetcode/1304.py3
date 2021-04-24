class Solution:
    def sumZero(self, n: int) -> List[int]:
        res = [0] * n
        for i in range(0, n - 1, 2):
            res[i] = i + 1
            res[i + 1] = -(i + 1)
        return (res)