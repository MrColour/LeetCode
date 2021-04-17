class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        total = 0
        top = []
        right = []
        sideways = list(zip(*grid))
        for i in range(len(grid)):
            right += [max(grid[i])]
            top += [max(sideways[i])]
        
        print(top)
        print(right)
            
        for i, line in enumerate(grid):
            for j, n in enumerate(line):
                dif = min(top[j], right[i])
                total += abs(grid[i][j] - dif)
        return (total)