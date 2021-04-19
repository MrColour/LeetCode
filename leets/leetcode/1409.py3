from collections import deque

class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        p = deque([x + 1 for x in range(len(queries))])

        for thing in p:
            print(thing)

        for i in range(m):
            take = p.remove(queries[i])
            print(take)
            p.appendleft(take)