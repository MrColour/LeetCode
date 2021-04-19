from collections import deque

class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        p = deque([x + 1 for x in range(m)])

        # for thing in p:
        #     print(thing)

        res = []
        for i in queries:
            pos = p.index(i)
            res += [pos]
            p.remove(i)
            p.appendleft(i)
            
        return (res)