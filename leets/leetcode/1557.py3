def exclude(which, canidates, edges):
    canidates[which] = 1

    for num in edges[which]:
        if (canidates[num] == 0):
            exclude(num, canidates, edges)

class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        canidates = [0] * n
        path = defaultdict(list)
        
        for pair in edges:
            path[pair[0]] += [pair[1]]

        for i in range(n):
            if (canidates[i] == 0):
                for to in path[i]:    
                    exclude(to, canidates, path)

        res = [x for x in range(n) if canidates[x] == 0]
        return (res)