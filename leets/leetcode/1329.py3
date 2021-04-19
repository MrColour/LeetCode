def sort_dia(matrix, x, y):
    length = len(matrix[0])
    height = len(matrix)

    collect = []
    sx, sy = x, y
    while (x < length and y < height):
        collect += [matrix[y][x]]
        x += 1
        y += 1
    
    # print(collect)
    collect = sorted(collect)
    for num in collect:
        matrix[sy][sx] = num
        sy += 1
        sx += 1

class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        x = 0
        for i in range(len(mat[0])):
            sort_dia(mat, x, 0)
            x += 1

        y = 0
        for i in range(1, len(mat)):
            sort_dia(mat, 0, y)
            y += 1

        return (mat)