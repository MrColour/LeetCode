import itertools as it

class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        res = set([])
        symbos = list(tiles)
        
        for i in range(1, len(tiles) + 1):
            gather = set(it.permutations(symbos, i))
            res |= gather

        return (len(res))