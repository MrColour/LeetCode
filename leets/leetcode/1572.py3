class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        x = 0
        y = 0

        res = 0
        for i in range(len(mat)):
            res += mat[y][x]
            res += mat[y][len(mat) - x - 1]

            x += 1
            y += 1

        if (len(mat) % 2 == 1):
            mid = len(mat) // 2
            res -= mat[mid][mid]
        return (res)