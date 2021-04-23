def traverse(grid, choosen, res, x, y, curr, need):
    if (x > len(grid[0]) - 1 or x < 0):
        return
    if (y > len(grid) - 1 or y < 0):
        return

    if (grid[y][x] == -1 or choosen[y][x] == 1 or grid[y][x] == 1):
        return

    if (grid[y][x] == 2 and curr == need):
        res[0] += 1
        return

    choosen[y][x] = 1

    traverse(grid, choosen, res, x + 1, y + 0, curr + 1, need)
    traverse(grid, choosen, res, x - 1, y + 0, curr + 1, need)
    traverse(grid, choosen, res, x + 0, y + 1, curr + 1, need)
    traverse(grid, choosen, res, x + 0, y - 1, curr + 1, need)

    choosen[y][x] = 0


class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        choosen = [[0] * len(grid[0]) for x in range(len(grid))]

        res = [0]
        x, y = 0, 0
        cross = 0
        for i, row in enumerate(grid):
            for j, num in enumerate(row):
                if (num == 1):
                    x = j
                    y = i
                elif (num == 0):
                    cross += 1

        cross += 1
        traverse(grid, choosen, res, x + 1, y + 0, 1, cross)
        traverse(grid, choosen, res, x - 1, y + 0, 1, cross)
        traverse(grid, choosen, res, x + 0, y + 1, 1, cross)
        traverse(grid, choosen, res, x + 0, y - 1, 1, cross)
        return (res[0])