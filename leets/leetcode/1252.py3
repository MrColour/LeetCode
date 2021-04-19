class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        mat = [[0] * n for x in range(m)]
        
        for index in indices:
            for i in range(len(mat[0])):
                mat[index[0]][i] += 1
                
            for i in range(len(mat)):
                mat[i][index[1]] += 1
                
                
        match = 0
        for row in mat:
            for num in row:
                if (num % 2 == 1):
                    match += 1
        return (match)