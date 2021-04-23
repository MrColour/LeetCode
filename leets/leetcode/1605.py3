class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        mat = [[0] * len(colSum) for x in range(len(rowSum))]

        mat[0] = colSum

        for i, row in enumerate(mat):
            at = -rowSum[i]
            print("start ", at)
            for j, num in enumerate(row):
                at += num
                if (at > 0):
                    mat[i][j] = num - at
                    mat[i + 1][j] += at
                    at = 0
        return (mat)